#include <gtest/gtest.h>

#include "helpers/string.hpp"

TEST(string__starts_with, empty_source_empty_starting) {
    ASSERT_TRUE(helpers::string::starts_with("", ""));
}

TEST(string__starts_with, empty_source_non_empty_starting) {
    ASSERT_FALSE(helpers::string::starts_with("", "test"));
}

TEST(string__starts_with, source_not_contains_starting) {
    ASSERT_FALSE(helpers::string::starts_with("hello", "test"));
}

TEST(string__starts_with, source_contains_starting) {
    ASSERT_TRUE(helpers::string::starts_with("hello", "he"));
}