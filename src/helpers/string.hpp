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
    };
}

#endif //LIBMIMES_STRING_HPP
