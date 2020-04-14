#include "desktop_finder.hpp"

#include <algorithm>
#include "desktop_parser.hpp"
#include "../helpers/directory.hpp"
#include "../helpers/environment.hpp"

namespace desktop {

    std::vector<std::string> desktop_finder::find_associated_applications(const std::string &mime_type) {
        std::vector<std::string> result;

        // Получить приложения из папки пользователя
        std::vector<std::string> paths{helpers::environment::compute_user_application_folder(),
                                       helpers::environment::system_application_path};

        for (const auto &directory_path: paths) {
            if (helpers::directory::is_exists(directory_path)) {
                auto absolute_file_names = helpers::directory::get_file_names(directory_path, ".desktop");
                for (const auto &absolute_file_path: absolute_file_names) {
                    auto desktop_file = desktop_parser::parse_file(absolute_file_path);
                    if (std::find(desktop_file.supported_mime_types.begin(), desktop_file.supported_mime_types.end(),
                                  mime_type) != desktop_file.supported_mime_types.end()) {
                        result.emplace_back(desktop_file.file_name);
                    }
                }
            }
        }

        return result;
    }
}