#include "base_exception.hpp"

namespace exceptions {

    base_exception::base_exception(std::string message) : m_message(std::move(message)) {}

    const char * base_exception::what() const noexcept {
        return m_message.c_str();
    }

}