#ifndef LIBMIMES_MIME_APPLICATIONS_PARSER_HPP
#define LIBMIMES_MIME_APPLICATIONS_PARSER_HPP

#include "base_parser.hpp"
#include "mime_applications.hpp"

namespace mime {
    /**
     * Парсер файлов mimeapps.list
     */
    struct mime_applications_parser : base_parser {
        /**
         * Разобрать файл mimeapps.list
         *
         * @param file_path Абсолютный путь к файлу.
         * @return Список ассоциаций из файла.
         */
        static mime_applications* parse_file(const std::string &file_path);

    private:
        static const std::string added_associations_section_name;
        static const std::string removed_associations_section_name;
        static const std::string default_applications_section_name;
    };
}

#endif //LIBMIMES_MIME_APPLICATIONS_PARSER_HPP
