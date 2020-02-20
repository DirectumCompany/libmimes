#include "file_stat_read_exception.hpp"

namespace exceptions {
    file_stat_read_exception::file_stat_read_exception() : base_exception("Cannot read file stat.") {}
}