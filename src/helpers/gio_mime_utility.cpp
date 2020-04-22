#include "gio_mime_utility.hpp"

#include "command.hpp"

namespace helpers {

    std::string gio_mime_utility::get_executable_path() const {
        static std::string executable_path = "/usr/bin/gio";
        return executable_path;
    }

    std::string gio_mime_utility::get_mime_type(const std::string &file_path) const {
        // Получить информацию о файле
        command get_file_info(get_executable_path());
        get_file_info.add_param("info", "\"" + file_path + "\"");

        // Найти нужную строку
        command grep_mime_type("grep");
        grep_mime_type.add_param("standard::content-type");
        get_file_info.add_param("|", grep_mime_type.get_command_text());

        // Выделить нужное
        command cut("cut");
        cut.add_param("-d' '", "-f4");
        get_file_info.add_param("|", cut.get_command_text());
        return get_file_info.execute();
    }

}