#ifndef LIBMIMES_BASE_PARSER_HPP
#define LIBMIMES_BASE_PARSER_HPP

#include <string>
#include <vector>

#include "mime_cache.hpp"

namespace mime {

    struct base_parser {
        /**
         * Разобрать строку из файла mimeapps.list
         *
         * @param source Исходная строка.
         * @return Пара ключ-значение. Ключ - MIME-тип, значение - список приложений.
         */
        static std::pair<std::string, std::vector<std::string>> parse_string(const std::string &source);
    };
}

#endif //LIBMIMES_BASE_PARSER_HPP
