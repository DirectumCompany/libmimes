#ifndef LIBMIMES_APPLICATIONS_LIST_HPP
#define LIBMIMES_APPLICATIONS_LIST_HPP

#include <map>
#include <string>

namespace mime {
    /**
     * Представление файла mimeapps.list
     */
    struct applications_list {
        /**
         * Значения из секции [Added Associations].
         * Приложения поддерживают открытие этого типа MIME.
         */
        std::map<std::string, std::vector<std::string>> added_associations;

        /**
         * Значения из секции [Removed Associations].
         * Приложения не поддерживают этот тип MIME.
         */
        std::map<std::string, std::vector<std::string>> removed_associations;

        /**
         * Значения из секции [Default Applications].
         * Приложения должны выбираться по умолчанию для открытия этого типа MIME.
         */
        std::map<std::string, std::vector<std::string>> default_applications;
    };

}

#endif //LIBMIMES_APPLICATIONS_LIST_HPP
