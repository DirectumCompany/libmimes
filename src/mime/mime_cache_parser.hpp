#ifndef LIBMIMES_MIME_CACHE_PARSER_HPP
#define LIBMIMES_MIME_CACHE_PARSER_HPP

#include "mime_cache.hpp"

namespace mime {
    /**
     * Парсер файлов кэша MIME-типов.
     */
    struct mime_cache_parser {
        /**
         * Разобрать строку из файла mimeapps.list
         *
         * @param source Исходная строка.
         * @return Пара ключ-значение. Ключ - MIME-тип, значение - список приложений.
         */
        static std::pair<std::string, std::vector<std::string>> parse_string(const std::string &source);

        /**
         * Разобрать файл кэша ассоциаций.
         *
         * @param file_path Абсолютный путь к файлу.
         * @return Список ассоциаций из файла кэша.
         */
        static mime_cache* parse_file(const std::string &file_path);

    private:
        /**
         * Заголовок основной секции файла mimeapps.list
         */
        static const std::string m_mime_cache_header;
    };
}

#endif //LIBMIMES_MIME_CACHE_PARSER_HPP
