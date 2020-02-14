#ifndef LIBMIMES_PATH_HPP
#define LIBMIMES_PATH_HPP

#include <string>

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
        static char m_delimiter;
    };
}


#endif //LIBMIMES_PATH_HPP
