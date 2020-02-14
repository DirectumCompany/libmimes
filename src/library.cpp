#include "library.hpp"

#include "helpers/file.hpp"
#include "exceptions/file_not_found_exception.hpp"

std::string get_mime_type(const std::string &file_name) {
    if (!helpers::file::is_exists(file_name))
        throw exceptions::file_not_found_exception("File not found: " + file_name);
}
