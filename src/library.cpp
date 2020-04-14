#include "library.hpp"

#include <algorithm>

#include "desktop/desktop_finder.hpp"
#include "helpers/environment.hpp"
#include "helpers/file.hpp"
#include "helpers/path.hpp"
#include "mime/mime_cache_reader.hpp"
#include "mime/mime_database_reader.hpp"


namespace library {
    
    std::string get_mime_type(const std::string &file_path) {
        return helpers::file::get_mime_type(file_path);
    }

    std::string get_mime_type_by_extension(const std::string &file_path) {
        auto extension = helpers::path::extract_file_extension(file_path);
        std::transform(extension.begin(), extension.end(), extension.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        auto database = mime::mime_database_reader::get_instance()->get_actual_database();
        return database[extension];
    }

    std::vector<std::string> get_mime_type_associations(const std::string &mime_type) {
        auto mime_cache_reader = mime::mime_cache_reader::get_instance();
        auto mime_cache = mime_cache_reader->get_actual_cache();
        return mime_cache->associations[mime_type];
    }

    std::vector<std::string> find_associated_application_from_desktop_files(const std::string &mime_type) {
        return desktop::desktop_finder::find_associated_applications(mime_type);
    }
}