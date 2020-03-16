#ifndef LIBMIMES_PATH_HPP
#define LIBMIMES_PATH_HPP

#include <string>
#include <vector>

namespace helpers {
    /**
     * Вспомогательный класс работы с путями файловой системы.
     */
    struct path {
        /**
         * Получить текущую рабочую директорию.
         *
         * @return Абсолютный путь к папке, где находится текущий бинарный файл.
         */
        static std::string get_current_working_directory();

        /**
         * Извлечь имя файла из пути.
         *
         * @param file_path Путь к файлу.
         * @return Имя файла с расширением.
         */
        static std::string extract_file_name(const std::string &file_path);

        /**
         * Извлечь расширение файла.
         *
         * @param file_path Путь к файлу.
         * @return Расширение файла.
         */
        static std::string extract_file_extension(const std::string &file_path);

        /**
         * Объединить пути.
         *
         * @param args Список путей для объединения.
         * @return Путь, полученный в результате конкатенации.
         */
        static std::string join(std::initializer_list<std::string> args);

    private:
        /**
         * Разделитель папок в файловой системе.
         */
        static const char m_delimiter;
    };
}


#endif //LIBMIMES_PATH_HPP
