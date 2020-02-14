#include "file_not_found_exception.hpp"

#include <utility>

namespace exceptions {

    file_not_found_exception::file_not_found_exception(std::string error) : m_error(std::move(error)) {}

    const char *file_not_found_exception::what() const noexcept {
        return m_error.c_str();
    }
}
