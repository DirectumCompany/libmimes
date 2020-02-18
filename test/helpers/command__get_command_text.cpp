#include <gtest/gtest.h>

#include "helpers/command.hpp"

TEST(command_processor__get_command_text, wo_params) {
    helpers::command command_processor("uname");
    ASSERT_EQ(command_processor.get_command_text(), "uname");
}

TEST(command_processor__get_command_text, with_one_param_wo_value) {
    helpers::command command_processor("uname");
    command_processor.add_param("-a");
    ASSERT_EQ(command_processor.get_command_text(), "uname -a");
}

TEST(command_processor__get_command_text, with_one_param_with_value) {
    helpers::command command_processor("file");
    command_processor.add_param("-i", "test");
    ASSERT_EQ(command_processor.get_command_text(), "file -i test");
}

TEST(command_processor__get_command_text, with_multiple_params) {
    helpers::command command_processor("xdg-mime");
    command_processor.add_param("query");
    command_processor.add_param("default", "test");
    ASSERT_EQ(command_processor.get_command_text(), "xdg-mime query default test");
}