#include "mime_cache_builder.hpp"

#include <algorithm>

namespace mime {

    void mime_cache_builder::apply_overrides(mime_cache *const mime_cache,
                                             const mime_applications *const overrides_list) {

        std::map<std::string, std::vector<std::string>> temporary_associations;

        // Добавить переопределения из секции [Default Applications]
        for (const auto &item: overrides_list->default_applications) {
            temporary_associations[item.first] = std::vector<std::string>(item.second);
        }

        // Добавить переопределения из секции [Added Associations]
        for (const auto &item: overrides_list->added_associations) {
            if (temporary_associations.find(item.first) == temporary_associations.end()) {
                temporary_associations[item.first] = std::vector<std::string>();
            }
            for (const auto &association: item.second) {
                if (std::find(temporary_associations[item.first].begin(), temporary_associations[item.first].end(),
                              association) == temporary_associations[item.first].end()) {
                    temporary_associations[item.first].emplace_back(association);
                }
            }
        }

        // Внести изменения в исходный список
        for (const auto &association: temporary_associations) {
            if (mime_cache->associations.find(association.first) == mime_cache->associations.end()) {
                mime_cache->associations[association.first] = std::vector<std::string>();
            }

            // Удалить повторяющиеся элементы
            for (const auto &desktop_file_name: association.second) {
                mime_cache->associations[association.first].erase(
                        std::remove(mime_cache->associations[association.first].begin(),
                                    mime_cache->associations[association.first].end(), desktop_file_name),
                        mime_cache->associations[association.first].end());
            }

            // Объединить два списка... исходный должен уйти в конец
            mime_cache->associations[association.first].insert(mime_cache->associations[association.first].begin(),
                                                               association.second.begin(), association.second.end());
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