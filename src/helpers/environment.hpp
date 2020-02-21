#ifndef LIBMIMES_ENVIRONMENT_HPP
#define LIBMIMES_ENVIRONMENT_HPP

#include <string>

namespace helpers {
    /**
     * Вспомогательный класс для работы с окружением.
     */
    struct environment {
        /**
         * Получить значение переменной окружения.
         *
         * @param variable_name Наименование переменной окружения.
         * @return Значение переменной окружения. Если переменная окружения не найдена, возвращается пустая строка.
         */
        static std::string get_environment_variable_value(const std::string &variable_name);

        /**
         * Вычислить путь к файлу с пользовательскими переопределениями mimeapps.list
         *
         * @return Абсолютный путь ~/.config/mimeapps.list
         */
        static std::string compute_user_overrides_mime_apps_path();

        /**
         * Вычислить путь к файлу с переопределениями предоставляемые дистрибутивом по умолчанию.
         *
         * @return /usr/share/applications/defaults.list
         */
        static const std::string distribution_defaults_apps_path;

        /**
         * Путь к файлу кэша ассоциаций MIME-типов.
         */
        static const std::string mime_cache_file_path;
    };
}

#endif //LIBMIMES_ENVIRONMENT_HPP
