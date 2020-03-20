#include <gtest/gtest.h>

#include "desktop/desktop_parser.hpp"
#include "helpers/path.hpp"

TEST(desktop_parser__parse_file, wo_mime_types) {
    auto example_file_name = helpers::path::join(helpers::path::get_current_working_directory(),
                                                  "/test_case_data/desktop/wo_mime_types.desktop");
    auto result = desktop::desktop_parser::parse_file(example_file_name);
    ASSERT_EQ(result.file_name, "wo_mime_types.desktop");
    ASSERT_TRUE(result.supported_mime_types.empty());
}

TEST(desktop_parser__parse_file, one_mime_type) {
    auto example_file_name = helpers::path::join(helpers::path::get_current_working_directory(),
                                                  "/test_case_data/desktop/one_mime_type.desktop");
    auto result = desktop::desktop_parser::parse_file(example_file_name);
    ASSERT_EQ(result.file_name, "one_mime_type.desktop");
    ASSERT_EQ(result.supported_mime_types, std::vector<std::string>({ "x-scheme-handler/waagent54" }));
}

TEST(desktop_parser__parse_file, multiple_mime_types) {
    auto example_file_name = helpers::path::join(helpers::path::get_current_working_directory(),
                                                  "/test_case_data/desktop/multiple_mime_types.desktop");
    auto result = desktop::desktop_parser::parse_file(example_file_name);
    ASSERT_EQ(result.file_name, "multiple_mime_types.desktop");
    ASSERT_EQ(result.supported_mime_types, std::vector<std::string>({ "x-scheme-handler/waagent54", "application/gzip" }));
}
