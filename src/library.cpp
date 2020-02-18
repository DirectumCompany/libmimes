#include "library.hpp"

#include "helpers/environment.hpp"
#include "helpers/file.hpp"
#include "mime/mime_cache_parser.hpp"

std::string get_mime_type(const std::string &file_path) {
    return helpers::file::get_mime_type(file_path);
}

std::vector<std::string> get_mime_type_associations(const std::string &mime_type) {
    auto mime_cache = mime::mime_cache_parser::parse_file(helpers::environment::mime_cache_file_path);
    return mime_cache.associations[mime_type];
}