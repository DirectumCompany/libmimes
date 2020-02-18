#ifndef MIMES_LIBRARY_HPP
#define MIMES_LIBRARY_HPP

#include <string>

/**
 * Получить MIME-type указанного файла.
 *
 * @param file_path Абсолютный путь к файлу.
 * @return MIME-type файла.
 * @throws exceptions::file_not_found_exception
 */
std::string get_mime_type(const std::string &file_path);

#endif //MIMES_LIBRARY_HPP
