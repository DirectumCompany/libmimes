#include "file_mime_utility.hpp"

#include "command.hpp"

namespace helpers {

    std::string file_mime_utility::get_executable_path() const {
        static std::string executable_path = "/usr/bin/file";
        return executable_path;
    }

    std::string file_mime_utility::get_mime_type(const std::string &file_path) const {
        command detect_mime_type(get_executable_path());
        detect_mime_type.add_param("--brief");
        detect_mime_type.add_param("--dereference");
        detect_mime_type.add_param("--mime-type");
        detect_mime_type.add_param("\"" + file_path + "\"");
        return detect_mime_type.execute();
    }

}