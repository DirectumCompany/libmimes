#include <gtest/gtest.h>

#include "helpers/path.hpp"

TEST(path__join, one_param) {
    ASSERT_EQ(helpers::path::join("/usr"), "/usr");
}

TEST(path__join, two_params) {
    ASSERT_EQ(helpers::path::join("/usr", "/bin"), "/usr/bin");
}

TEST(path__join, multiple_params) {
    ASSERT_EQ(helpers::path::join("/usr", "/local", "/bin", "/python"), "/usr/local/bin/python");
}

TEST(path__join, multiple_params_wo_delimiter) {
    ASSERT_EQ(helpers::path::join("/usr", "local", "bin", "python"), "/usr/local/bin/python");
}

TEST(path__join, multiple_delimiters) {
    ASSERT_EQ(helpers::path::join("/usr/", "/bin"), "/usr/bin");
}

TEST(path__join, wo_slash_at_begin) {
    ASSERT_EQ(helpers::path::join("directory", "file"), "directory/file");
}