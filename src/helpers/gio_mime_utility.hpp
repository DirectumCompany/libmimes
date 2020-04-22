#ifndef LIBMIMES_GIO_MIME_UTILITY_HPP
#define LIBMIMES_GIO_MIME_UTILITY_HPP

#include "mime_utility.hpp"

namespace helpers {
    /**
     * Утилита gio.
     */
    struct gio_mime_utility : mime_utility {

        std::string get_mime_type(const std::string &file_path) const override;

        std::string get_executable_path() const override;
    };
}

#endif //LIBMIMES_GIO_MIME_UTILITY_HPP
