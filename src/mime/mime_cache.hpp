#ifndef LIBMIMES_MIME_CACHE_HPP
#define LIBMIMES_MIME_CACHE_HPP

#include <string>
#include <map>
#include <vector>

namespace mime {
    /**
     * Класс представления файла mimeinfo.cache
     */
    struct mime_cache {
        /**
         * Список ассоциаций из файла mimeinfo.cache
         */
        std::map<std::string, std::vector<std::string>> associations;
    };
}


#endif //LIBMIMES_MIME_CACHE_HPP
