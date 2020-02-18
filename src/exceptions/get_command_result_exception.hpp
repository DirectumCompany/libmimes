#ifndef LIBMIMES_GET_COMMAND_RESULT_EXCEPTION_HPP
#define LIBMIMES_GET_COMMAND_RESULT_EXCEPTION_HPP

#include "base_exception.hpp"

namespace exceptions {

    struct get_command_result_exception : base_exception {
        /**
         * Конструктор.
         */
        get_command_result_exception();
    };
}

#endif //LIBMIMES_GET_COMMAND_RESULT_EXCEPTION_HPP
