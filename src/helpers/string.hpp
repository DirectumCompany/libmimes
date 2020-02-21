#ifndef LIBMIMES_STRING_HPP
#define LIBMIMES_STRING_HPP

#include <string>
#include <vector>

namespace helpers {
    /**
     * Вспомогательный класс по работе со строками.
     */
    struct string {
        /**
         * Разделить строку по разделителю.
         *
         * @param source Исходная строка.
         * @param delimiter Разделитель.
         * @return Список строк, полученных в результате разделения.
         */
        static std::vector<std::string> split(const std::string &source, char delimiter = ' ');

        /**
         * Проверить, что строка оканчивается на другую строку.
         *
         * @param source Исходная строка.
         * @param ending Строка, на которую должна окончиться исходная.
         * @return true - если строка заканчивается на указанную, иначе false.
         */
        static bool ends_with(const std::string &source, const std::string &ending);
    };
}

#endif //LIBMIMES_STRING_HPP
