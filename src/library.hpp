#ifndef MIMES_LIBRARY_HPP
#define MIMES_LIBRARY_HPP

#include <string>
#include <vector>

struct library {
    /**
     * Получить MIME-type указанного файла.
     *
     * @param file_path Абсолютный путь к файлу.
     * @return MIME-type файла.
     * @throws exceptions::cannot_found_exception
     */
    static std::string get_mime_type(const std::string &file_path);

    /**
     * Получить назначенные ассоциации с указанным MIME-типом.
     * @param mime_type MIME-тип.
     * @return Список назначенных ассоциаций из кэша ОС.
     */
    static std::vector<std::string> get_mime_type_associations(const std::string &mime_type);

    /**
     * Получить список подходящих приложений из ярлыков приложений.
     *
     * @param mime_type MIME-тип.
     * @return Подходящие приложения.
     */
    static std::vector<std::string> find_associated_application_from_desktop_files(const std::string &mime_type);
};

#endif //MIMES_LIBRARY_HPP
