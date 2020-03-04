#include <gtest/gtest.h>
#include <string>

#include "helpers/file.hpp"
#include "helpers/path.hpp"

TEST(file__is_exists, is_exists) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto file_path = helpers::path::join({current_directory, "test_case_data", "helpers", "file"});
    ASSERT_TRUE(helpers::file::is_exists(file_path));
}

TEST(file__is_exists, not_found) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto file_path = helpers::path::join({current_directory, "test_case_data", "helpers", ".file"});
    ASSERT_FALSE(helpers::file::is_exists(file_path));
}

TEST(file__is_exists, space_in_file_name) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto file_path = helpers::path::join({current_directory, "test_case_data", "helpers", ".file"});
    ASSERT_FALSE(helpers::file::is_exists(file_path));
}
