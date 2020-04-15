#include "mime_cache_parser.hpp"

#include <fstream>

#include "../exceptions/not_found_exception.hpp"
#include "../helpers/file.hpp"

namespace mime {

    mime_cache* mime_cache_parser::parse_file(const std::string &file_path) {
        if (!helpers::file::is_exists(file_path))
            throw exceptions::not_found_exception(file_path);

        auto result = new mime_cache();

        std::ifstream mime_cache_file(file_path);
        std::string row;

        while (getline(mime_cache_file, row)) {
            if (!row.empty() && row != m_get_mime_cache_header()) {
                result->associations.insert(parse_string(row));
            }
        }
        mime_cache_file.close();

        return result;
    }

    const std::string& mime_cache_parser::m_get_mime_cache_header() {
        static const std::string m_mime_cache_header = "[MIME Cache]";
        return m_mime_cache_header;
    }
}