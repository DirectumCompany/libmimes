#include "environment.hpp"

#include <cstdlib>

#include "path.hpp"

namespace helpers {

    const std::string environment::mime_cache_file_path = "/usr/share/applications/mimeinfo.cache";
    const std::string environment::distribution_defaults_apps_path = "/usr/share/applications/defaults.list";
    const std::string environment::distribution_mime_apps_path = "/usr/share/applications/mimeapps.list";
    const std::string environment::system_application_path = "/usr/share/applications";
    const std::string environment::system_mime_database_path = "/usr/share/mime";

    std::string environment::get_environment_variable_value(const std::string &variable_name) {
        return std::getenv(variable_name.c_str());
    }

    std::string environment::compute_user_overrides_mime_apps_path() {
        auto home_folder_path = get_environment_variable_value("HOME");
        return path::join(home_folder_path, ".config", "mimeapps.list");
    }

    std::string environment::compute_deferred_user_overrides_mime_apps_path() {
        auto home_folder_path = get_environment_variable_value("HOME");
        return path::join(home_folder_path, ".local", "share", "applications", "mimeapps.list");
    }

    std::string environment::compute_user_application_folder() {
        auto home_folder_path = get_environment_variable_value("HOME");
        return path::join(home_folder_path, ".local", "share", "applications");
    }
}