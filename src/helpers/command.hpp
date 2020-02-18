#ifndef LIBMIMES_COMMAND_HPP
#define LIBMIMES_COMMAND_HPP

#include <string>
#include <vector>

namespace helpers {
    /**
     * Команда для исполнения в терминале.
     */
    struct command {

        /**
         * Добавить параметр.
         *
         * @param param Имя параметра.
         */
        void add_param(const std::string &param);

        /**
         * Добавить параметр со значением.
         *
         * @param name Имя параметра.
         * @param value Значение параметра.
         */
        void add_param(const std::string &name, const std::string &value);

        /**
         * Получить текст команды для выполнения в терминале.
         *
         * @return Текст команды для выполнения в терминале.
         */
        std::string get_command_text();

        /**
         * Выполнить команду в терминале.
         *
         * @return Результат выполнения команды.
         */
        std::string execute();

        /**
         * Конструктор.
         *
         * @param command Команда для исполнения.
         */
        explicit
        command(std::string command);

    private:
        /**
         * Исполняемая команда.
         */
        std::string m_command;

        /**
         * Список параметров команды.
         */
        std::vector<std::pair<std::string, std::string>> m_params;
    };
}

#endif //LIBMIMES_COMMAND_HPP
