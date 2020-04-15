#include "not_found_exception.hpp"

namespace exceptions {
    not_found_exception::not_found_exception(std::string file_path) : base_exception(std::move(file_path)) {}
}
