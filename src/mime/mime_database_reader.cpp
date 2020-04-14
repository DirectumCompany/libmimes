#include "mime_database_reader.hpp"

#include <algorithm>

#include "../helpers/directory.hpp"
#include "../helpers/environment.hpp"
#include "../helpers/file.hpp"
#include "mime_database_file_parser.hpp"

namespace mime {

    mime_database_reader *mime_database_reader::m_instance = nullptr;

    mime_database_reader::mime_database_reader() : m_database_last_modification_date(0) {}

    mime_database_reader *mime_database_reader::get_instance() {
        if (!m_instance) {
            m_instance = new mime_database_reader();
        }
        return m_instance;
    }

    std::map<std::string, std::string> mime_database_reader::get_actual_database() {
        if (helpers::directory::is_exists(helpers::environment::system_mime_database_path)) {
            // Получить список файлов для анализа
            auto mime_database_files = helpers::directory::get_file_names(
                    helpers::environment::system_mime_database_path,
                    ".xml");

            // Проверить необходимость актуализации базы данных
            time_t last_modification_date = 0, current_file_modification_date;
            for (const auto &mime_database_path: mime_database_files) {
                current_file_modification_date = helpers::file::get_last_modification_date(mime_database_path);
                if (last_modification_date < current_file_modification_date) {
                    last_modification_date = current_file_modification_date;
                }
            }

            if (last_modification_date > m_database_last_modification_date) {
                m_database_last_modification_date = last_modification_date;
                for (const auto &mime_database_path: mime_database_files) {
                    auto mime_associations = mime_database_file_parser::parse_file(mime_database_path);
                    for (const auto &item: mime_associations) {
                        m_database[item.first] = item.second;
                    }
                }
            }
        }

        return m_database;
    }
}