#include <gtest/gtest.h>

#include "helpers/string.hpp"

TEST(string__ltrim, wo_spaces_at_begin) {
    std::string source = "Hello, world!";
    ASSERT_EQ(helpers::string::ltrim(source), source);
}

TEST(string__ltrim, with_spaces_at_begin) {
    ASSERT_EQ(helpers::string::ltrim("  Hello, world!"), "Hello, world!");
}

TEST(string__ltrim, with_spaces_at_begin_and_end) {
    ASSERT_EQ(helpers::string::ltrim("  Hello, world!  "), "Hello, world!  ");
}