#include <gtest/gtest.h>

#include "helpers/string.hpp"

TEST(string__ends_with, no_match) {
    ASSERT_FALSE(helpers::string::ends_with("source", "test"));
}

TEST(string__ends_with, empty_ending) {
    ASSERT_TRUE(helpers::string::ends_with("source", ""));
}

TEST(string__ends_with, one_letter_string_success) {
    ASSERT_TRUE(helpers::string::ends_with("eee", "e"));
}

TEST(string__ends_with, ending_great) {
    ASSERT_FALSE(helpers::string::ends_with("eee", "eeee"));
}

TEST(string__ends_with, empty_source) {
    ASSERT_FALSE(helpers::string::ends_with("", "e"));
}

TEST(string__ends_with, empty_source_empty_ending) {
    ASSERT_TRUE(helpers::string::ends_with("", ""));
}