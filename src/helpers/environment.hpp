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
         * Вычислить путь к устаревшему файлу с пользовательскими переопределениями mimeapps.list
         *
         * @return Абсолютный путь ~/.config/mimeapps.list
         */
        static std::string compute_deferred_user_overrides_mime_apps_path();

        /**
         * Вычислить путь к пользовательской папке приложений.
         *
         * @return Абсолютный путь к папке ~/.local/share/applications
         */
        static std::string compute_user_application_folder();

        /**
         * Получить путь к файлу с переопределениями предоставляемые дистрибутивом по умолчанию.
         */
        static const std::string &get_distribution_defaults_apps_path();

        /**
         * Получить путь к файлу с переопределениями предоставляемые дистрибутивом по умолчанию.
         */
        static const std::string &get_distribution_mime_apps_path();

        /**
         * Получить путь к файлу кэша ассоциаций MIME-типов.
         */
        static const std::string &get_mime_cache_file_path();

        /**
         * Получить путь к системной папке приложений.
         */
        static const std::string &get_system_application_path();

        /**
         * Получить путь к системной папке базы MIME-типов.
         */
        static const std::string &get_system_mime_database_path();


    };
}

#endif //LIBMIMES_ENVIRONMENT_HPP
