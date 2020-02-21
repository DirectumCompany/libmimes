#include "cannot_found_exception.hpp"

namespace exceptions {
    cannot_found_exception::cannot_found_exception(std::string file_path) : base_exception(std::move(file_path)) {}
}
