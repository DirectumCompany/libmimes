#ifndef LIBMIMES_DESKTOP_FINDER_HPP
#define LIBMIMES_DESKTOP_FINDER_HPP

#include <string>
#include <vector>

namespace desktop {
    /**
     * Класс для поиска по desktop-файлам.
     */
    struct desktop_finder {
        /**
         * Получить приложение-обработчик указанного MIME-типа.
         *
         * @param mime_type MIME-тип, для которого необходимо найти приложение редактор.
         * @return Имя desktop-файла приложения-обработчика.
         */
        static std::vector<std::string> find_associated_applications(const std::string &mime_type);
    };

}

#endif //LIBMIMES_DESKTOP_FINDER_HPP
