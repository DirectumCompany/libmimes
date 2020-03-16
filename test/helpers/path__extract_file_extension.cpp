#include <gtest/gtest.h>

#include "helpers/path.hpp"

TEST(path__extract_file_extension, wo_extension) {
    ASSERT_EQ(helpers::path::extract_file_extension("/usr/bin/sh"), "");
}

TEST(path__extract_file_extension, wo_extension_with_dot_in_path) {
    ASSERT_EQ(helpers::path::extract_file_extension("/tmp/.local/sh"), "");
}

TEST(path__extract_file_extension, with_extension) {
    ASSERT_EQ(helpers::path::extract_file_extension("/tmp/test.docx"), "docx");
}

TEST(path__extract_file_extension, with_extension_with_dot_in_path) {
    ASSERT_EQ(helpers::path::extract_file_extension("/tmp/.local/test.docx"), "docx");
}