#ifndef LIBMIMES_MIME_APPLICATIONS_HPP
#define LIBMIMES_MIME_APPLICATIONS_HPP

#include <map>
#include <string>
#include <vector>

namespace mime {
    /**
     * Представление файла mimeapps.list
     */
    struct mime_applications {
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

#endif //LIBMIMES_MIME_APPLICATIONS_HPP
