#ifndef LIBMIMES_MIME_CACHE_BUILDER_HPP
#define LIBMIMES_MIME_CACHE_BUILDER_HPP

#include "mime_applications.hpp"
#include "mime_cache.hpp"

namespace mime {
    /**
     * Построить кэш из mimeapps.list
     */
    struct mime_cache_builder {
        /**
         * Применить перекрытие.
         *
         * @param mime_cache Текущий кэш.
         * @param overrides_list Список ассоциаций для переопределения.
         */
        static void apply_overrides(mime_cache *mime_cache, const mime_applications &overrides_list);

        /**
         * Получить кэш из списка ассоциаций.
         *
         * @param applications_list Список ассоциаций.
         * @return Кэш.
         */
        static mime_cache *from_mime_applications(const mime_applications &applications_list);

    private:
        /**
         * Удалить MIME-типы, для которых не осталось ассоциаций в кэше.
         *
         * @param mime_cache Кэш, для которого производится чистка.
         */
        static void remove_empty_entries(mime_cache *mime_cache);

    };
}

#endif //LIBMIMES_MIME_CACHE_BUILDER_HPP
