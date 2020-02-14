#include "string.hpp"

#include <sstream>

namespace helpers {

    std::vector<std::string> string::split(const std::string &source, char delimiter) {
        std::istringstream ss(source);
        std::string token;
        std::vector<std::string> result;

        while (std::getline(ss, token, delimiter)) {
            result.push_back(token);
        }

        return result;
    }
}
