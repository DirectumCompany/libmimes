#include "path.hpp"

#include <cstdio>
#include <unistd.h>

namespace helpers {

    const char path::m_delimiter = '/';

    std::string path::get_current_working_directory() {
        char buff[FILENAME_MAX];
        getcwd(buff, FILENAME_MAX);
        return std::string(buff);
    }

    std::string path::join(std::initializer_list<std::string> args) {
        std::string result;

        for (const auto &item: args) {
            if (result[result.size() - 1] != m_delimiter && item[0] != m_delimiter) {
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
