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
         * Путь к файлу, который не был найден.
         */
        std::string m_file_path;

    public:
        const char *what() const noexcept override;

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
