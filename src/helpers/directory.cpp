#include "directory.hpp"

#include <algorithm>
#include <dirent.h>
#include "../exceptions/cannot_found_exception.hpp"
#include "../helpers/string.hpp"
#include "path.hpp"

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
                        result.emplace_back(helpers::path::join({directory_path, file_name}));
                    }
                } else if (ent->d_type == DT_DIR) {
                    auto subdirectory_name = std::string(ent->d_name);
                    if (subdirectory_name != "." && subdirectory_name != "..") {
                        auto subdirectory_path = helpers::path::join({directory_path, subdirectory_name});
                        auto subdirectory_files = get_file_names(subdirectory_path, extension);
                        result.insert(result.end(), subdirectory_files.begin(), subdirectory_files.end());
                    }
                }
            }
            closedir(dir);
        }

        std::sort(result.begin(), result.end());
        return result;
    }

}