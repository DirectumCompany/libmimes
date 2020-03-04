#include "mime_database_file_parser.hpp"

#include <fstream>
#include "../helpers/string.hpp"

namespace mime {

    std::map<std::string, std::string> mime_database_file_parser::parse_file(const std::string &file_path) {
        std::map<std::string, std::string> result;
        std::ifstream mime_database_file_stream(file_path);
        std::string row;

        bool is_type_detected = false;
        std::string type, pattern;
        while (getline(mime_database_file_stream, row)) {
            row = helpers::string::ltrim(row);
            if (is_type_detected) {
                if (helpers::string::starts_with(row, "<glob")) {
                    auto tokens = helpers::string::split(row);
                    for (const auto &token: tokens) {
                        if (helpers::string::starts_with(token, "pattern")) {
                            auto pattern_tokens = helpers::string::split(token, '=');
                            pattern = pattern_tokens[1];
                            pattern = pattern.substr(3, pattern.size() - 1);
                            pattern = pattern.substr(0, pattern.size() - 3);
                            result[pattern] = type;
                            is_type_detected = false;
                            break;
                        }
                    }
                }
            } else {
                if (helpers::string::starts_with(row, "<mime-type")) {
                    auto tokens = helpers::string::split(row);
                    for (const auto &token: tokens) {
                        if (helpers::string::starts_with(token, "type=")) {
                            auto type_tokens = helpers::string::split(token, '=');
                            type = type_tokens[1];
                            type = type.substr(1, type.size() - 1);
                            type = type.substr(0, type.size() - 2);
                            is_type_detected = true;
                        }
                    }
                }
            }
        }

        mime_database_file_stream.close();
        return result;
    }
}