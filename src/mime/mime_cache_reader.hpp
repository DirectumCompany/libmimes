#ifndef LIBMIMES_MIME_CACHE_READER_HPP
#define LIBMIMES_MIME_CACHE_READER_HPP

#include "mime_cache.hpp"

namespace mime {
    /**
     * Кэш файлов mimeinfo.cache
     */
    struct mime_cache_reader {

        /**
         * Получить экземпляр класса.
         *
         * @return Экземпляр класса.
         */
        static mime_cache_reader* get_instance();

        /**
         * Получить актуальный кэш ассоциаций MIME-типов.
         *
         * @return Актуальный кэш ассоциаций MIME-типов.
         */
        mime_cache* get_actual_cache();

        /**
         * Конструктор.
         */
        mime_cache_reader();

        /**
         * Деструктор.
         */
        ~mime_cache_reader();

    private:
        /**
         * Экземпляр класса.
         */
        static mime_cache_reader* m_instance;

        /**
         * Актуальный кэш. Синхронизируется при попытке доступа.
         */
        mime_cache* m_mime_cache;

        /**
         * Время последнего изменения файла кэша.
         */
        time_t m_mime_cache_last_modification_date;
    };
}

#endif //LIBMIMES_MIME_CACHE_READER_HPP
