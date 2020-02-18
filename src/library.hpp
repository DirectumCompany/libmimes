#ifndef MIMES_LIBRARY_HPP
#define MIMES_LIBRARY_HPP

#include <string>
#include <vector>

/**
 * Получить MIME-type указанного файла.
 *
 * @param file_path Абсолютный путь к файлу.
 * @return MIME-type файла.
 * @throws exceptions::file_not_found_exception
 */
std::string get_mime_type(const std::string &file_path);

/**
 * Получить назначенные ассоциации с указанным MIME-типом.
 * @param mime_type MIME-тип.
 * @return Список назначенных ассоциаций из кэша ОС.
 */
std::vector<std::string> get_mime_type_associations(const std::string &mime_type);

#endif //MIMES_LIBRARY_HPP
