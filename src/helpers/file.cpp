#include "file.hpp"

#include <fstream>
#include <sys/stat.h>
#include <regex>

#include "../exceptions/not_found_exception.hpp"
#include "../exceptions/file_stat_read_exception.hpp"
#include "../helpers/string.hpp"
#include "mime_utility.hpp"
#include "file_mime_utility.hpp"
#include "gio_mime_utility.hpp"

namespace helpers {

    bool file::is_exists(const std::string &file_path) {
        std::ifstream file_stream(file_path);
        bool result = file_stream.good();
        file_stream.close();
        return result;
    }

    std::string file::get_mime_type(const std::string &file_path) {
        if (!is_exists(file_path))
            throw exceptions::not_found_exception(file_path);

        std::vector<mime_utility *> mime_utilities = {
                new gio_mime_utility(),
                new file_mime_utility(),
        };

        std::string result;
        for (auto &utility: mime_utilities) {
            if (utility->is_available()) {
                result = utility->get_mime_type(file_path);
                if (!result.empty())
                    break;
            }
            delete utility;
        }

        return result;
    }

    time_t file::get_last_modification_date(const std::string &file_path) {
        if (!is_exists(file_path))
            throw exceptions::not_found_exception(file_path);

        struct stat result{};
        if (stat(file_path.c_str(), &result) == 0) {
            return result.st_mtime;
        }
        throw exceptions::file_stat_read_exception();
    }
}
