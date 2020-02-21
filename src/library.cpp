#include "library.hpp"

#include "desktop/desktop_finder.hpp"
#include "helpers/environment.hpp"
#include "helpers/file.hpp"
#include "mime/mime_cache_reader.hpp"

std::string library::get_mime_type(const std::string &file_path) {
    return helpers::file::get_mime_type(file_path);
}

std::vector<std::string> library::get_mime_type_associations(const std::string &mime_type) {
    auto mime_cache_reader = mime::mime_cache_reader::get_instance();
    auto mime_cache = mime_cache_reader->get_actual_cache();
    return mime_cache->associations[mime_type];
}

std::vector<std::string> library::find_associated_application_from_desktop_files(const std::string &mime_type) {
    return desktop::desktop_finder::find_associated_applications(mime_type);
}