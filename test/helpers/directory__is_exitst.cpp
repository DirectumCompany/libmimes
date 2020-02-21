#include <gtest/gtest.h>

#include "helpers/directory.hpp"
#include "helpers/path.hpp"

TEST(directory__is_exists, success) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto directory_path = helpers::path::join({current_directory, "test_case_data"});
    ASSERT_TRUE(helpers::directory::is_exists(directory_path));
}

TEST(directory__is_exists, failure) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto directory_path = helpers::path::join({current_directory, "some_unique_folder_name"});
    ASSERT_FALSE(helpers::directory::is_exists(directory_path));
}