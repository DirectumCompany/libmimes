#include <gtest/gtest.h>

#include "helpers/path.hpp"

TEST(path__extract_file_path, empty) {
    ASSERT_EQ(helpers::path::extract_file_name(""), "");
}

TEST(path__extract_file_path, only_file_name) {
    ASSERT_EQ(helpers::path::extract_file_name("test"), "test");
}

TEST(path__extract_file_path, relative_path_in_current_folder) {
    ASSERT_EQ(helpers::path::extract_file_name("./test"), "test");
}

TEST(path__extract_file_path, relative_path_in_subfolder) {
    ASSERT_EQ(helpers::path::extract_file_name("./folder/test"), "test");
}

TEST(path__extract_file_path, absolute_path) {
    ASSERT_EQ(helpers::path::extract_file_name("/usr/bin/test"), "test");
}