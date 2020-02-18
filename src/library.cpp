#include "library.hpp"

#include "helpers/file.hpp"
#include "exceptions/file_not_found_exception.hpp"

std::string get_mime_type(const std::string &file_path) {
    return helpers::file::get_mime_type(file_path);
}
