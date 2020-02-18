#include <gtest/gtest.h>

#include "helpers/command.hpp"

TEST(command__execute, echo_string) {
    helpers::command echo_command("echo");
    echo_command.add_param("test");
    ASSERT_EQ(echo_command.execute(), "test");
}

TEST(command__execute, echo_empty) {
    helpers::command echo_command("echo");
    ASSERT_EQ(echo_command.execute(), "");
}

TEST(command__execute, echo_to_dev_null) {
    helpers::command echo_command("echo");
    echo_command.add_param(">>", "/dev/null");
    ASSERT_EQ(echo_command.execute(), "");
}