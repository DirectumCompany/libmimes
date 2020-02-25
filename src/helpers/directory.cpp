#include "directory.hpp"

#include <algorithm>
#include <dirent.h>
#include "../exceptions/cannot_found_exception.hpp"
#include "../helpers/string.hpp"

namespace helpers {

    bool directory::is_exists(const std::string &directory_path) {
        DIR *dir = opendir(directory_path.c_str());
        if (dir) {
            closedir(dir);
            return true;
        }
        return false;
    }

    std::vector<std::string>
    directory::get_file_names(const std::string &directory_path, const std::string &extension) {
        if (!helpers::directory::is_exists(directory_path))
            throw exceptions::cannot_found_exception(directory_path);

        std::vector<std::string> result;

        DIR *dir;
        struct dirent *ent;

        std::string file_name;
        if ((dir = opendir(directory_path.c_str())) != nullptr) {
            while ((ent = readdir(dir)) != nullptr) {
                if (ent->d_type == DT_REG) {
                    file_name = ent->d_name;
                    if (extension.empty() || helpers::string::ends_with(file_name, extension)) {
                        result.emplace_back(file_name);
                    }
                }
            }
            closedir(dir);
        }

        std::sort(result.begin(), result.end());
        return result;
    }

}