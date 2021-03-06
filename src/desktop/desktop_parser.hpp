#ifndef LIBMIMES_DESKTOP_PARSER_HPP
#define LIBMIMES_DESKTOP_PARSER_HPP

#include <string>
#include "desktop_entry.hpp"

namespace desktop {
    /**
     * Парсер файлов *.desktop
     */
    struct desktop_parser {
        /**
         * Распарсить файл *.desktop
         *
         * @param file_path Абсолютный путь к файлу.
         * @return Разобранный файл *.desktop
         */
        static desktop_entry parse_file(const std::string &file_path);

    private:

        /**
         * Получить наименование свойства, хранящего список обрабатываемых MIME-типов.
         */
        static const std::string &m_get_mime_type_property_name();
    };
}

#endif //LIBMIMES_DESKTOP_PARSER_HPP
