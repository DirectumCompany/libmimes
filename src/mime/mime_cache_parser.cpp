#include "mime_cache_parser.hpp"

#include <fstream>

#include "../exceptions/file_not_found_exception.hpp"
#include "../helpers/file.hpp"
#include "../helpers/string.hpp"

namespace mime {

    const std::string mime_cache_parser::m_mime_cache_header = "[MIME Cache]";

    std::pair<std::string, std::vector<std::string>> mime_cache_parser::parse_string(const std::string &source) {
        auto string_tokens = helpers::string::split(source, '=');
        auto mime_type = string_tokens[0];
        auto applications = helpers::string::split(string_tokens[1], ';');
        return {mime_type, applications};
    }

    mime_cache mime_cache_parser::parse_file(const std::string &file_path) {
        if (!helpers::file::is_exists(file_path))
            throw exceptions::file_not_found_exception(file_path);

        mime_cache result;

        std::ifstream mime_cache_file(file_path);
        std::string row;

        while (getline(mime_cache_file, row)) {
            if (!row.empty() && row != m_mime_cache_header) {
                result.associations.insert(parse_string(row));
            }
        }

        return result;
    }
}