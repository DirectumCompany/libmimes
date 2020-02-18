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
    };
}

#endif //LIBMIMES_FILE_HPP
