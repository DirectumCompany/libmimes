#ifndef LIBMIMES_ENVIRONMENT_HPP
#define LIBMIMES_ENVIRONMENT_HPP

#include <string>

namespace helpers {
    /**
     * Вспомогательный класс для работы с окружением.
     */
    struct environment {
        /**
         * Путь к файлу кэша ассоциаций MIME-типов.
         */
        static const std::string mime_cache_file_path;
    };
}

#endif //LIBMIMES_ENVIRONMENT_HPP
