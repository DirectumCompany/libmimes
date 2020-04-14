#ifndef LIBMIMES_MIME_CACHE_PARSER_HPP
#define LIBMIMES_MIME_CACHE_PARSER_HPP

#include "base_parser.hpp"
#include "mime_cache.hpp"

namespace mime {
    /**
     * Парсер файлов кэша MIME-типов.
     */
    struct mime_cache_parser : base_parser {
        /**
         * Разобрать файл кэша ассоциаций.
         *
         * @param file_path Абсолютный путь к файлу.
         * @return Список ассоциаций из файла кэша.
         */
        static mime_cache *parse_file(const std::string &file_path);

    private:
        /**
         * Заголовок основной секции файла mimeapps.list
         */
        static const std::string& m_get_mime_cache_header();
    };
}

#endif //LIBMIMES_MIME_CACHE_PARSER_HPP
