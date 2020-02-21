#include "base_parser.hpp"

#include "../helpers/string.hpp"

namespace mime {
    std::pair<std::string, std::vector<std::string>> base_parser::parse_string(const std::string &source) {
        auto string_tokens = helpers::string::split(source, '=');
        auto mime_type = string_tokens[0];
        auto applications = helpers::string::split(string_tokens[1], ';');
        return {mime_type, applications};
    }
}
