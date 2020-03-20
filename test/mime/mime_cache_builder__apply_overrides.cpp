#include <gtest/gtest.h>

#include "mime/mime_applications.hpp"
#include "mime/mime_cache.hpp"
#include "mime/mime_cache_builder.hpp"

/**
 * Имитирует ситуацию, когда в файле /usr/share/applications/mimeapps.list содержится:
 * [Added Associations]
 * application/vnd.oasis.opendocument.spreadsheet=calc.desktop;gnumeric.desktop;kf5-org.kde.calligrasheets.desktop;
 *
 *
 * А в файле ~/.config/mimeapps.list содержится:
 * [Default Applications]
 * application/vnd.oasis.opendocument.spreadsheet=calc.desktop
 *
 * [Added Associations]
 * application/vnd.oasis.opendocument.spreadsheet=openoffice4-calc.desktop;desktopeditors.desktop;r7-office-desktopeditors.desktop;calc.desktop;myoffice-table.desktop;
 */
TEST(mime_cache_builder__apply_overrides, two_files) {
    // Подготовить системный кэш
    auto system_cache = new mime::mime_cache();
    system_cache->associations.insert({
        "application/vnd.oasis.opendocument.spreadsheet",
        {
            "calc.desktop",
            "gnumeric.desktop",
            "kf5-org.kde.calligrasheets.desktop"
        }
    });

    // Подготовить пользовательское переопределение
    auto user_applications = new mime::mime_applications();
    user_applications->default_applications.insert({
        "application/vnd.oasis.opendocument.spreadsheet",
        {
            "calc.desktop",
        }
    });
    user_applications->added_associations.insert({
        "application/vnd.oasis.opendocument.spreadsheet",
        {
            "openoffice4-calc.desktop",
            "desktopeditors.desktop",
            "r7-office-desktopeditors.desktop",
            "calc.desktop",
            "myoffice-table.desktop"
        }
    });
    mime::mime_cache_builder::apply_overrides(system_cache, user_applications);
    std::map<std::string, std::vector<std::string>> expected_result = {
            {
                    "application/vnd.oasis.opendocument.spreadsheet",
                    {
                            "calc.desktop",
                            "openoffice4-calc.desktop",
                            "desktopeditors.desktop",
                            "r7-office-desktopeditors.desktop",
                            "myoffice-table.desktop",
                            "gnumeric.desktop",
                            "kf5-org.kde.calligrasheets.desktop"
                    }
            }
    };
    ASSERT_EQ(system_cache->associations, expected_result);
}