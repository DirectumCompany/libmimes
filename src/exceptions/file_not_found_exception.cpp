#include "file_not_found_exception.hpp"

#include <utility>

namespace exceptions {

    file_not_found_exception::file_not_found_exception(std::string file_path) : m_file_path(std::move(file_path)) {}

    const char *file_not_found_exception::what() const noexcept {
        return m_file_path.c_str();
    }
}
