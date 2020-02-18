#include "parser.hpp"

#include <fstream>

#include "../exceptions/file_not_found_exception.hpp"
#include "../helpers/file.hpp"
#include "../helpers/string.hpp"
#include "section.hpp"

namespace mime {

    constexpr auto parser::get_added_associations_section_name() {
        return "[Added Associations]";
    }

    constexpr auto parser::get_removed_associations_section_name() {
        return "[Removed Associations]";
    }

    constexpr auto parser::get_default_applications_section_name() {
        return "[Default Applications]";
    }

    std::pair<std::string, std::vector<std::string>> parser::parse_string(const std::string &source) {
        auto string_tokens = helpers::string::split(source, '=');
        auto mime_type = string_tokens[0];
        auto applications = helpers::string::split(string_tokens[1], ';');
        return {mime_type, applications};
    }

    applications_list parser::parse_file(const std::string &file_path) {
        applications_list result;

        if (!helpers::file::is_exists(file_path))
            throw exceptions::file_not_found_exception("File not found: " + file_path);

        std::ifstream mime_apps_file(file_path);
        std::string token;
        auto current_section = section::added_associations;

        while (getline(mime_apps_file, token)) {
            if (!token.empty()) {
                if (token == get_added_associations_section_name()) {
                    current_section = section::added_associations;
                } else if (token == get_removed_associations_section_name()) {
                    current_section = section::removed_associations;
                } else if (token == get_default_applications_section_name()) {
                    current_section = section::default_applications;
                } else {
                    auto items = parse_string(token);
                    switch (current_section) {
                        case section::added_associations:
                            result.added_associations.insert(items);
                            break;
                        case section::removed_associations:
                            result.removed_associations.insert(items);
                            break;
                        case section::default_applications:
                            result.default_applications.insert(items);
                            break;
                    }
                }
            }
        }

        return result;
    }
}
