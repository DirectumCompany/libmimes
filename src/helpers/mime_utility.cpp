#include "mime_utility.hpp"

#include "file.hpp"

namespace helpers {
    bool mime_utility::is_available() const {
        return file::is_exists(get_executable_path());
    }
}