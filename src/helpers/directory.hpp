#ifndef LIBMIMES_DIRECTORY_HPP
#define LIBMIMES_DIRECTORY_HPP

#include <string>
#include <vector>

namespace helpers {
    /**
     * Вспомогательный класс по работе с директориями.
     */
    struct directory {
        /**
         * Проверить наличие директории в файловой системе.
         *
         * @param directory_path Абсолютный путь к директории.
         * @return true - директория найдена, иначе false.
         */
        static bool is_exists(const std::string &directory_path);

        /**
         * Получить список файлов в директории.
         *
         * @param directory_path Абсолютный путь к директории.
         * @param extension Расширение искомого файла.
         * @return Список файлов, соответствующи
         */
        static std::vector<std::string>
        get_file_names(const std::string &directory_path, const std::string &extension = "");

    };
}

#endif //LIBMIMES_DIRECTORY_HPP
