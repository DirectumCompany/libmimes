#include "file.hpp"

#include <fstream>

namespace helpers {

    bool file::is_exists(const std::string &file_name) {
        std::ifstream file_stream(file_name);
        return file_stream.good();
    }
}
