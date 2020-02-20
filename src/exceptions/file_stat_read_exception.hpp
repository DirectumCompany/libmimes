#ifndef LIBMIMES_FILE_STAT_READ_EXCEPTION_HPP
#define LIBMIMES_FILE_STAT_READ_EXCEPTION_HPP

#include "base_exception.hpp"

namespace exceptions {
    /**
     * Исключение при попытке выполнения команды.
     */
    struct file_stat_read_exception: base_exception {
        /**
         * Конструктор класса.
         */
        file_stat_read_exception();
    };
}

#endif //LIBMIMES_FILE_STAT_READ_EXCEPTION_HPP
