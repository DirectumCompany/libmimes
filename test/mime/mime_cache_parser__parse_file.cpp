#include <gtest/gtest.h>
#include <map>
#include <memory>
#include <string>

#include "helpers/path.hpp"
#include "mime/mime_cache_parser.hpp"

TEST(mime_cache_parser__parse_file, all) {
    auto example_file_name = helpers::path::join({helpers::path::get_current_working_directory(),
                                                  "/test_case_data/mime/parser/mimeinfo.cache"});
    auto mime_cache = std::shared_ptr<mime::mime_cache>(mime::mime_cache_parser::parse_file(example_file_name));
    ASSERT_EQ(mime_cache->associations.size(), 2);
    std::map<std::string, std::vector<std::string>> expected_associations = {
            {"application/csv", {"libreoffice-calc.desktop"}},
            {"application/ogg", {"io.elementary.music.desktop", "io.elementary.videos.desktop"}},
    };
    ASSERT_EQ(mime_cache->associations, expected_associations);
}