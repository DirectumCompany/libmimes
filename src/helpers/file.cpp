#include "file.hpp"

#include <fstream>
#include <sys/stat.h>
#include <regex>

#include "../exceptions/not_found_exception.hpp"
#include "../exceptions/file_stat_read_exception.hpp"
#include "../helpers/command.hpp"
#include "../helpers/string.hpp"

namespace helpers {

    bool file::is_exists(const std::string &file_path) {
        std::ifstream file_stream(file_path);
        bool result = file_stream.good();
        file_stream.close();
        return result;
    }

    std::string file::get_mime_type(const std::string &file_path) {
        if (!is_exists(file_path))
            throw exceptions::not_found_exception(file_path);

        // Получить результат выполнения команды file -i <file_path>
        helpers::command command("file");
        command.add_param("-i", "\"" + file_path + "\"");
        auto command_result = command.execute();
        return file::extract_mime_type(command_result);
    }

    std::string file::extract_mime_type(const std::string &source) {
        std::regex regexp(R"(:\s[\w.-]+\/[\w.+-]+)");
        std::smatch matches;
        std::regex_search(source, matches, regexp);
        std::string result;
        if (!matches.empty()) {
            result = matches[0];
            return result.substr(2);
        }
        return result;
    }

    time_t file::get_last_modification_date(const std::string &file_path) {
        if (!is_exists(file_path))
            throw exceptions::not_found_exception(file_path);

        struct stat result{};
        if (stat(file_path.c_str(), &result) == 0) {
            return result.st_mtime;
        }
        throw exceptions::file_stat_read_exception();
    }
}
