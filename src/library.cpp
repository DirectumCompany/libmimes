#include "library.hpp"

#include "helpers/environment.hpp"
#include "helpers/file.hpp"
#include "mime/mime_cache_reader.hpp"

std::string get_mime_type(const std::string &file_path) {
    return helpers::file::get_mime_type(file_path);
}

std::vector<std::string> get_mime_type_associations(const std::string &mime_type) {
    auto mime_cache_reader = mime::mime_cache_reader::get_instance();
    auto mime_cache = mime_cache_reader->get_actual_cache();
    return mime_cache->associations[mime_type];
}