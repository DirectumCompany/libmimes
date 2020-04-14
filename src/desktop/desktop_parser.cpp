#include "desktop_parser.hpp"

#include <fstream>
#include "../exceptions/cannot_found_exception.hpp"
#include "../helpers/file.hpp"
#include "../helpers/path.hpp"
#include "../helpers/string.hpp"

namespace desktop {

    desktop_entry desktop_parser::parse_file(const std::string &file_path) {
        if (!helpers::file::is_exists(file_path))
            throw exceptions::cannot_found_exception(file_path);

        desktop_entry result;
        result.file_name = helpers::path::extract_file_name(file_path);

        std::ifstream desktop_file_stream(file_path);
        std::string row;

        while (getline(desktop_file_stream, row)) {
            if (!row.empty() && row != m_get_desktop_entry_header()) {
                auto tokens = helpers::string::split(row, '=');
                if (tokens.size() > 1 && tokens[0] == m_get_mime_type_property_name()) {
                    result.supported_mime_types = helpers::string::split(tokens[1], ';');
                }
            }
        }
        desktop_file_stream.close();

        return result;
    }

    const std::string &desktop_parser::m_get_desktop_entry_header() {
        static const std::string desktop_entry_header = "[Desktop Entry]";
        return desktop_entry_header;
    }

    const std::string &desktop_parser::m_get_mime_type_property_name() {
        static const std::string mime_type_property_name = "MimeType";
        return mime_type_property_name;
    }
}