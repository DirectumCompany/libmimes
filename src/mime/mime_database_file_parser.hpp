#ifndef LIBMIMES_MIME_DATABASE_FILE_PARSER_HPP
#define LIBMIMES_MIME_DATABASE_FILE_PARSER_HPP

#include <map>
#include <string>

namespace mime {
    /**
     * Класс для парсинга файлов базы данных MIME-типов.
     */
    struct mime_database_file_parser {
        /**
         * Разобрать файл базы данных MIME-типов.
         *
         * @param file_path Абсолютный путь к файлу.
         * @return Словарь, где ключ - маска файла, значение - наименование MIME-типа.
         */
        static std::map<std::string, std::string> parse_file(const std::string &file_path);

    };
}



#endif //LIBMIMES_MIME_DATABASE_FILE_PARSER_HPP
