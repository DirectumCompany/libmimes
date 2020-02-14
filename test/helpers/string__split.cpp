#include <gtest/gtest.h>

#include "helpers/string.hpp"

TEST(string__split, empty) {
    auto result = helpers::string::split("");
    ASSERT_TRUE(result.empty());
}

TEST(string__split, one_token) {
    std::string source = "Hello";
    auto result = helpers::string::split(source);
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result[0], source);
}

TEST(string__split, two_tokens) {
    auto result = helpers::string::split("Hello world");
    ASSERT_EQ(result.size(), 2);
    ASSERT_EQ(result[0], "Hello");
    ASSERT_EQ(result[1], "world");
}

TEST(string__split, mulitple_tokens_with_custom_delimiter) {
    auto result = helpers::string::split("Hello-C++-world", '-');
    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(result[0], "Hello");
    ASSERT_EQ(result[1], "C++");
    ASSERT_EQ(result[2], "world");
}
