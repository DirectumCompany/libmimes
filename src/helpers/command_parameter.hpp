#ifndef LIBMIMES_COMMAND_PARAMETER_HPP
#define LIBMIMES_COMMAND_PARAMETER_HPP

#include <string>

namespace helpers {
    /**
     * Параметр командной строки.
     */
    struct command_parameter {
        /**
         * Наименование параметра.
         */
        std::string name;

        /**
         * Значение параметра.
         */
        std::string value;
    };
}

#endif //LIBMIMES_COMMAND_PARAMETER_HPP
