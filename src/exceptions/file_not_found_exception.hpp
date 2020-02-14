#ifndef LIBMIMES_FILE_NOT_FOUND_EXCEPTION_HPP
#define LIBMIMES_FILE_NOT_FOUND_EXCEPTION_HPP

#include <exception>
#include <string>

namespace exceptions {
    /**
     * Исключение о недоступности файла.
     */
    struct file_not_found_exception : std::exception {
        /**
         * Сообщение об ошибке.
         */
        std::string m_error;

    public:
        const char *what() const noexcept override;

        /**
         * Конструктор.
         *
         * @param error Сообщение об ошибке.
         */
        explicit
        file_not_found_exception(std::string error);

    };
}

#endif //LIBMIMES_FILE_NOT_FOUND_EXCEPTION_HPP
