#ifndef LIBMIMES_NOT_FOUND_EXCEPTION_HPP
#define LIBMIMES_NOT_FOUND_EXCEPTION_HPP

#include "base_exception.hpp"

namespace exceptions {
    /**
     * Исключение, которое сообщает о несуществующем файле по указанному пути.
     */
    struct not_found_exception : base_exception {
        /**
         * Конструктор.
         *
         * @param file_path Путь к файлу, который не был найден.
         */
        explicit
        not_found_exception(std::string file_path);
    };
}

#endif //LIBMIMES_NOT_FOUND_EXCEPTION_HPP
