#ifndef LIBMIMES_DESKTOP_ENTRY_HPP
#define LIBMIMES_DESKTOP_ENTRY_HPP

#include <string>
#include <vector>

namespace desktop {
    /**
     * Представление файла *.desktop
     */
    struct desktop_entry {
        /**
         * Имя файла с расширением.
         */
        std::string file_name;

        /**
         * Поддерживаемые MIME-типы.
         */
        std::vector<std::string> supported_mime_types;

    };
}

#endif //LIBMIMES_DESKTOP_ENTRY_HPP
