#include "path.hpp"

#include <algorithm>
#include <dirent.h>
#include <cstdio>
#include <unistd.h>

#include "string.hpp"

namespace helpers {

    const char path::m_delimiter = '/';

    std::string path::get_current_working_directory() {
        char buff[FILENAME_MAX];
        getcwd(buff, FILENAME_MAX);
        return std::string(buff);
    }

    std::string path::extract_file_name(const std::string &file_path) {
        auto position = file_path.rfind(m_delimiter);
        if (position != std::string::npos) {
            return file_path.substr(position + 1, file_path.size() - 1);
        }

        return file_path;
    }

    std::string path::extract_file_extension(const std::string &file_path) {
        auto file_name = extract_file_name(file_path);
        auto tokens = string::split(file_name, '.');
        if (tokens.size() > 1) {
            return tokens[tokens.size() - 1];
        }
        return "";
    }

    std::string path::join(std::initializer_list<std::string> args) {
        std::string result;

        for (const auto &item: args) {
            if (result[result.size() - 1] != m_delimiter && item[0] != m_delimiter && !result.empty()) {
                result += m_delimiter;
            }

            result += item;
        }

        std::string double_delimiter = "//";
        size_t position = result.find(double_delimiter);
        if (position != std::string::npos) {
            result.replace(position, double_delimiter.size(), {m_delimiter});
        }

        return result;
    }
}
