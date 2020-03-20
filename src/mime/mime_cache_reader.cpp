#include "mime_cache_reader.hpp"

#include <string>
#include <vector>

#include "../helpers/environment.hpp"
#include "../helpers/file.hpp"
#include "mime_applications_parser.hpp"
#include "mime_cache_parser.hpp"
#include "mime_cache_builder.hpp"

namespace mime {

    mime_cache_reader *mime_cache_reader::m_instance = nullptr;

    mime_cache_reader::mime_cache_reader() : m_mime_cache(nullptr), m_mime_cache_last_modification_date(0) {}

    mime_cache_reader::~mime_cache_reader() {
        destroy_cache();
    }

    mime_cache_reader *mime_cache_reader::get_instance() {
        if (!m_instance) {
            m_instance = new mime_cache_reader();
        }
        return m_instance;
    }

    mime_cache *mime_cache_reader::get_actual_cache() {
        time_t last_modification_date = 0;
        std::vector<std::string> pathes;
        auto cache_exists = helpers::file::is_exists(helpers::environment::mime_cache_file_path);
        if (helpers::file::is_exists(helpers::environment::mime_cache_file_path)) {
            last_modification_date =
                    helpers::file::get_last_modification_date(helpers::environment::mime_cache_file_path);


            if (!m_mime_cache || m_mime_cache_last_modification_date < last_modification_date) {

                m_mime_cache_last_modification_date = last_modification_date;
                m_mime_cache = mime::mime_cache_parser::parse_file(helpers::environment::mime_cache_file_path);
            }
        } else {
            if (helpers::file::is_exists(helpers::environment::distribution_defaults_apps_path)) {
                pathes.emplace_back(helpers::environment::distribution_defaults_apps_path);
            }
            if (helpers::file::is_exists(helpers::environment::distribution_mime_apps_path)) {
                pathes.emplace_back(helpers::environment::distribution_mime_apps_path);
            }
        }

        if (helpers::file::is_exists(helpers::environment::compute_deferred_user_overrides_mime_apps_path())) {
            pathes.emplace_back(helpers::environment::compute_deferred_user_overrides_mime_apps_path());
        }
        if (helpers::file::is_exists(helpers::environment::compute_user_overrides_mime_apps_path())) {
            pathes.emplace_back(helpers::environment::compute_user_overrides_mime_apps_path());
        }
        for (const auto &path: pathes) {
            auto file_modification_date = helpers::file::get_last_modification_date(path);
            if (last_modification_date < file_modification_date) {
                last_modification_date = file_modification_date;
            }
        }

        if (m_mime_cache_last_modification_date < last_modification_date) {
            destroy_cache();
            if (cache_exists) {
                m_mime_cache = mime::mime_cache_parser::parse_file(helpers::environment::mime_cache_file_path);
            } else {
                m_mime_cache = new mime_cache();
            }

            for (const auto &path: pathes) {
                auto applications_list = mime_applications_parser::parse_file(path);
                mime_cache_builder::apply_overrides(m_mime_cache, applications_list);
            }

            m_mime_cache_last_modification_date = last_modification_date;
        }

        return m_mime_cache;
    }

    void mime_cache_reader::destroy_cache() {
        if (m_mime_cache) {
            delete m_mime_cache;
            m_mime_cache = nullptr;
        }
    }

}