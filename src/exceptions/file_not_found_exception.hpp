#ifndef LIBMIMES_FILE_NOT_FOUND_EXCEPTION_HPP
#define LIBMIMES_FILE_NOT_FOUND_EXCEPTION_HPP

#include "base_exception.hpp"

namespace exceptions {
    /**
     * Исключение о недоступности файла.
     */
    struct file_not_found_exception : base_exception {
        /**
         * Конструктор.
         *
         * @param file_path Путь к файлу, который не был найден.
         */
        explicit
        file_not_found_exception(std::string file_path);
    };
}

#endif //LIBMIMES_FILE_NOT_FOUND_EXCEPTION_HPP
