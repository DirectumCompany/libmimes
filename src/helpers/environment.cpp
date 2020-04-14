#include "environment.hpp"

#include <cstdlib>

#include "path.hpp"

namespace helpers {

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

    const std::string &environment::get_distribution_defaults_apps_path() {
        static const std::string distribution_defaults_apps_path = "/usr/share/applications/defaults.list";
        return distribution_defaults_apps_path;
    }

    const std::string &environment::get_distribution_mime_apps_path() {
        static const std::string distribution_mime_apps_path = "/usr/share/applications/mimeapps.list";
        return distribution_mime_apps_path;
    }

    const std::string &environment::get_mime_cache_file_path() {
        static const std::string mime_cache_file_path = "/usr/share/applications/mimeinfo.cache";
        return mime_cache_file_path;
    }

    const std::string &environment::get_system_application_path() {
        static const std::string system_application_path = "/usr/share/applications";
        return system_application_path;
    }

    const std::string &environment::get_system_mime_database_path() {
        static const std::string system_mime_database_path = "/usr/share/mime";
        return system_mime_database_path;
    }
}