#include "mime_cache_reader.hpp"

#include "../helpers/environment.hpp"
#include "mime_cache_parser.hpp"
#include "../helpers/file.hpp"

namespace mime {

    mime_cache_reader* mime_cache_reader::m_instance = nullptr;

    mime_cache_reader::mime_cache_reader() : m_mime_cache(nullptr), m_mime_cache_last_modification_date(0) {}

    mime_cache_reader::~mime_cache_reader() {
        destroy_cache();
    }

    mime_cache_reader* mime_cache_reader::get_instance()  {
        if (!m_instance) {
            m_instance = new mime_cache_reader();
        }
        return m_instance;
    }

    mime_cache * mime_cache_reader::get_actual_cache() {
        auto last_modification_date =
                helpers::file::get_last_modification_date(helpers::environment::mime_cache_file_path);
        if (!m_mime_cache || m_mime_cache_last_modification_date < last_modification_date) {
            destroy_cache();
            m_mime_cache_last_modification_date = last_modification_date;
            m_mime_cache = mime::mime_cache_parser::parse_file(helpers::environment::mime_cache_file_path);
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