#ifndef LIBMIMES_MIME_DATABASE_READER_HPP
#define LIBMIMES_MIME_DATABASE_READER_HPP

#include <map>

namespace mime {
    /**
     * Строитель актуальной базы MIME-типов.
     */
    struct mime_database_reader {

        /**
         * Получить экземпляр класса.
         *
         * @return Экземпляр класса.
         */
        static mime_database_reader *get_instance();

        /**
         * Получить актуальную базу MIME-типов.
         *
         * @return Актуальная база MIME-типов.
         */
        std::map<std::string, std::string> get_actual_database();


    private:
        /**
         * Конструктор.
         */
        mime_database_reader();

        /**
         * Экземпляр класса.
         */
        static mime_database_reader *m_instance;

        /**
         * Текущая база MIME-типов.
         */
        std::map<std::string, std::string> m_database;

        /**
         * Дата последнего изменения файлов базы данных.
         */
        time_t m_database_last_modification_date;

        /**
         * База MIME-типов.
         */
        std::map<std::string, std::string> m_mime_database;
    };
}

#endif //LIBMIMES_MIME_DATABASE_READER_HPP
