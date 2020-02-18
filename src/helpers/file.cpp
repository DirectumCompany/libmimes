#include "file.hpp"

#include <fstream>

namespace helpers {

    bool file::is_exists(const std::string &file_path) {
        std::ifstream file_stream(file_path);
        return file_stream.good();
    }
}
