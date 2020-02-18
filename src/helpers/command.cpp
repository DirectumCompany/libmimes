#include "command.hpp"

#include <climits>
#include <cstdio>

#include "../exceptions/execute_command_failed_exception.hpp"
#include "../exceptions/get_command_result_exception.hpp"

namespace helpers {

    command::command(std::string command) : m_command(std::move(command)) {}

    void command::add_param(const std::string &param) {
        add_param(param, "");
    }

    void command::add_param(const std::string &name, const std::string &value) {
        m_params.emplace_back(std::make_pair(name , value));
    }

    std::string command::get_command_text() {
        std::string command_text = m_command;

        if (!m_params.empty()) {
            for (const auto &pair: m_params) {
                if (!pair.first.empty()) {
                    command_text += " " + pair.first;
                }
                if (!pair.second.empty()) {
                    command_text += " " + pair.second;
                }
            }
        }

        return command_text;
    }

    std::string command::execute() {
        char buffer[PIPE_BUF];
        std::string result;
        FILE* pipe = popen(get_command_text().c_str(), "r");
        if (!pipe) throw exceptions::execute_command_failed_exception();
        try {
            while (fgets(buffer, sizeof buffer, pipe) != nullptr) {
                result += buffer;
            }
        } catch (...) {
            pclose(pipe);
            throw exceptions::get_command_result_exception();
        }
        pclose(pipe);
        if (!result.empty()) {
            return result.substr(0, result.size() - 1);
        }
        return "";
    }
}