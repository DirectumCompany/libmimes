#ifndef LIBMIMES_BASE_EXCEPTION_HPP
#define LIBMIMES_BASE_EXCEPTION_HPP

#include <exception>
#include <string>

namespace exceptions {
    /**
     * Базовый класс исключения.
     */
    struct base_exception: std::exception {

        /**
         * @see std::exception::what
         */
        const char *what() const noexcept override;

    protected:
        /**
         * Конструктор исключения.
         *
         * @param message Сообщение об ошибке.
         */
        explicit base_exception(std::string message);

    private:
        /**
         * Сообщение об ошибке.
         */
        const std::string m_message;
    };
}

#endif //LIBMIMES_BASE_EXCEPTION_HPP
