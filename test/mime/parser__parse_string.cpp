#include <gtest/gtest.h>

#include "mime/parser.hpp"

#include <string>
#include <vector>

TEST(parser__parse_string, one_application) {
    auto result = mime::parser::parse_string("video/H264=bar.desktop");
    auto expected_applications = std::vector<std::string>{"bar.desktop"};
    auto expected_result = std::pair<std::string, std::vector<std::string>>{"video/H264", expected_applications};
    ASSERT_EQ(result, expected_result);
}

TEST(parser__parse_string, multiple_aplications) {
    auto result = mime::parser::parse_string("image/jpeg=bar.desktop;baz.desktop");
    auto expected_applications = std::vector<std::string>{"bar.desktop", "baz.desktop"};
    auto expected_result = std::pair<std::string, std::vector<std::string>>{"image/jpeg", expected_applications};
    ASSERT_EQ(result, expected_result);
}
