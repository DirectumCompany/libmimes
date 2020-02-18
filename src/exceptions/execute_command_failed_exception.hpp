#ifndef LIBMIMES_EXECUTE_COMMAND_FAILED_EXCEPTION_HPP
#define LIBMIMES_EXECUTE_COMMAND_FAILED_EXCEPTION_HPP

#include "base_exception.hpp"

namespace exceptions {
    /**
     * Исключение при попытке выполнения команды.
     */
    struct execute_command_failed_exception: base_exception {
        /**
         * Конструктор класса.
         */
        execute_command_failed_exception();
    };
}

#endif //LIBMIMES_EXECUTE_COMMAND_FAILED_EXCEPTION_HPP
