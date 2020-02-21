#ifndef LIBMIMES_CANNOT_FOUND_EXCEPTION_HPP
#define LIBMIMES_CANNOT_FOUND_EXCEPTION_HPP

#include "base_exception.hpp"

namespace exceptions {
    /**
     * Исключение о недоступности файла.
     */
    struct cannot_found_exception : base_exception {
        /**
         * Конструктор.
         *
         * @param file_path Путь к файлу, который не был найден.
         */
        explicit
        cannot_found_exception(std::string file_path);
    };
}

#endif //LIBMIMES_CANNOT_FOUND_EXCEPTION_HPP
