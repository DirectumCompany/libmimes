#include "mime_cache_builder.hpp"

#include <algorithm>

namespace mime {

    void mime_cache_builder::apply_overrides(mime_cache *const mime_cache,
                                             const mime_applications *const overrides_list) {

        // Добавить переопределения из секции [Default Applications]
        for (const auto &item: overrides_list->default_applications) {
            if (mime_cache->associations.find(item.first) == mime_cache->associations.end()) {
                mime_cache->associations[item.first] = std::vector<std::string>();
            }
            mime_cache->associations[item.first].insert(mime_cache->associations[item.first].begin(),
                                                        item.second.begin(), item.second.end());
        }

        // Применить секцию [Removed Associations]
        for (const auto &item: overrides_list->removed_associations) {
            auto iterator = mime_cache->associations.find(item.first);
            if (iterator != mime_cache->associations.end()) {
                // Попробуем найти элементы из списка удаленных ассоциаций
                for (const auto &application_to_remove: item.second) {
                    auto application_position = std::find(iterator->second.begin(), iterator->second.end(),
                                                          application_to_remove);
                    if (application_position != iterator->second.end()) {
                        iterator->second.erase(application_position);
                    }
                }
            }
        }

        // Добавить переопределения из секции [Added Associations]
        for (const auto &item: overrides_list->added_associations) {
            auto iterator = mime_cache->associations.find(item.first);
            if (mime_cache->associations.find(item.first) == mime_cache->associations.end()) {
                mime_cache->associations[item.first] = std::vector<std::string>();
            }
            mime_cache->associations[item.first].insert(mime_cache->associations[item.first].begin(),
                                                        item.second.begin(), item.second.end());
        }

        // Удалить пустые ассоциации MIME-типов
        remove_empty_entries(mime_cache);
    }

    mime_cache *mime_cache_builder::from_mime_applications(mime_applications *applications_list) {
        auto result = new mime_cache();
        apply_overrides(result, applications_list);
        return result;
    }

    void mime_cache_builder::remove_empty_entries(mime::mime_cache *mime_cache) {
        for (auto it = mime_cache->associations.begin(); it != mime_cache->associations.end();) {
            if (it->second.empty()) {
                it = mime_cache->associations.erase(it);
            } else {
                ++it;
            }
        }
    }
}