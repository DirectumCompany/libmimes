#ifndef LIBMIMES_MIME_UTILITY_HPP
#define LIBMIMES_MIME_UTILITY_HPP

#include <string>

namespace helpers {
    /**
     * Утилита для определения MIME-типа.
     */
    struct mime_utility {
        /**
         * Доступность утилиты.
         */
        bool is_available() const;

        /**
         * Результат определения MIME-типа.
         *
         * @param file_path Абсолютный путь к файлу.
         */
        virtual std::string get_mime_type(const std::string &file_path) const = 0;

        /**
         * Виртульный деструктор.
         */
        virtual ~mime_utility() = default;

    protected:
        /**
         * Получить путь к утилите.
         */
        virtual std::string get_executable_path() const = 0;
    };
}


#endif //LIBMIMES_MIME_UTILITY_HPP
