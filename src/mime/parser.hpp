#ifndef LIBMIMES_PARSER_HPP
#define LIBMIMES_PARSER_HPP

#include <string>
#include <string_view>
#include <vector>

#include "applications_list.hpp"

namespace mime {
    /**
     * Парсер файлов mimeapps.list
     */
    struct parser {
        /**
         * Разобрать строку из файла mimeapps.list
         *
         * @param source Исходная строка.
         * @return Пара ключ-значение. Ключ - MIME-тип, значение - список приложений.
         */
        static std::pair<std::string, std::vector<std::string>> parse_string(const std::string &source);

        /**
         * Разобрать файл mimeapps.list
         *
         * @param file_path Абсолютный путь к файлу.
         * @return Представление файла в виде структуры.
         */
        static applications_list parse_file(const std::string &file_path);

    private:
        static constexpr auto get_added_associations_section_name();
        static constexpr auto get_removed_associations_section_name();
        static constexpr auto get_default_applications_section_name();
    };

}

#endif //LIBMIMES_PARSER_HPP
