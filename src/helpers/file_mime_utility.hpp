#ifndef LIBMIMES_FILE_MIME_UTILITY_HPP
#define LIBMIMES_FILE_MIME_UTILITY_HPP

#include "mime_utility.hpp"

namespace helpers {
    /**
     * Утилита file.
     */
    struct file_mime_utility: mime_utility {

        std::string get_mime_type(const std::string &file_path) const override;

        std::string get_executable_path() const override;

    };

}

#endif //LIBMIMES_FILE_MIME_UTILITY_HPP
