#ifndef LIBMIMES_FILE_HPP
#define LIBMIMES_FILE_HPP

#include <string>

namespace helpers {
    /**
     * Вспомогательный класс работы с файлами.
     */
    struct file {
        /**
         * Проверить наличие файла в файловой системе.
         *
         * @param file_path Абсолютный путь к файлу.
         * @return true - файл найден в файловой системе, иначе false.
         */
        static bool is_exists(const std::string &file_path);

        /**
         * Получить MIME-тип файла.
         *
         * @param file_path Абсолютный путь к файлу.
         * @return MIME-тип файала.
         * @throws exceptions::cannot_found_exception
         */
        static std::string get_mime_type(const std::string &file_path);

        /**
         * Получить время последнего изменения файла.
         *
         * @param file_path Абсолютный путь к файлу.
         * @return Время последнего изменения файла.
         * @throws exceptions::cannot_found_exception
         * @throws exceptions::file_stat_read_exception
         */
        static time_t get_last_modification_date(const std::string &file_path);
    };
}

#endif //LIBMIMES_FILE_HPP
