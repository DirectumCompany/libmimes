#include "mime_applications_parser.hpp"

#include <fstream>

#include "../exceptions/cannot_found_exception.hpp"
#include "../helpers/file.hpp"
#include "mime_applications_file_section.hpp"

namespace mime {

    const std::string mime_applications_parser::added_associations_section_name = "[Added Associations]";
    const std::string mime_applications_parser::removed_associations_section_name = "[Removed Associations]";
    const std::string mime_applications_parser::default_applications_section_name = "[Default Applications]";

    mime_applications *mime_applications_parser::parse_file(const std::string &file_path) {
        if (!helpers::file::is_exists(file_path))
            throw exceptions::cannot_found_exception(file_path);

        auto result = new mime_applications();
        std::ifstream mime_apps_file(file_path);
        std::string token;
        auto current_section = mime_applications_file_section::added_associations;

        while (getline(mime_apps_file, token)) {
            if (!token.empty()) {
                if (token == added_associations_section_name) {
                    current_section = mime_applications_file_section::added_associations;
                } else if (token == removed_associations_section_name) {
                    current_section = mime_applications_file_section::removed_associations;
                } else if (token == default_applications_section_name) {
                    current_section = mime_applications_file_section::default_applications;
                } else {
                    auto items = parse_string(token);
                    switch (current_section) {
                        case mime_applications_file_section::added_associations:
                            result->added_associations.insert(items);
                            break;
                        case mime_applications_file_section::removed_associations:
                            result->removed_associations.insert(items);
                            break;
                        case mime_applications_file_section::default_applications:
                            result->default_applications.insert(items);
                            break;
                    }
                }
            }
        }
        mime_apps_file.close();

        return result;
    }

}