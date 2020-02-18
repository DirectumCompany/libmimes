#include "file_not_found_exception.hpp"

namespace exceptions {
    file_not_found_exception::file_not_found_exception(std::string file_path) : base_exception(std::move(file_path)) {}
}
