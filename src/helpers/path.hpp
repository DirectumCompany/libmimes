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
         * Объединение путей.
         *
         * @param first Первый путь для объединения.
         * @param other Дальнейший перечень путей для объединения.
         * @return Результат объединения. Функция производит чистку от дублирующихся разделителей.
         */
        template<typename ...Ts>
        static std::string join(const std::string &first, const Ts &... other);

        /**
         * Замыкание вариативного шаблона объединения путей.
         *
         * @param source Исходный путь.
         * @return Путь в неизменном виде.
         */
        static std::string join(const std::string &source);

    private:
        /**
         * Разделитель папок в файловой системе.
         */
        static const char m_delimiter;

        /**
         * Удалить двойной разделитель из пути.
         *
         * @param source Исходная строка, для которой проводятся изменения.
         */
        static void remove_double_delimiter(std::string &source);
    };
}

#include "path.ipp"

#endif //LIBMIMES_PATH_HPP
