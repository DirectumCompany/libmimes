#include <gtest/gtest.h>

#include "helpers/directory.hpp"
#include "helpers/path.hpp"

TEST(path__get_files_in_directory, get_all) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto directory_path = helpers::path::join({current_directory, "test_case_data/helpers/path"});
    auto result = helpers::directory::get_file_names(directory_path);
    ASSERT_EQ(result, std::vector<std::string>({".hidden", "agent.log", "test1.txt", "test2.txt"}));
}

TEST(path__get_files_in_directory, get_empty_results) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto directory_path = helpers::path::join({current_directory, "test_case_data/helpers/path"});
    auto result = helpers::directory::get_file_names(directory_path, ".docx");
    ASSERT_TRUE(result.empty());
}

TEST(path__get_files_in_directory, get_only_txt) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto directory_path = helpers::path::join({current_directory, "test_case_data/helpers/path"});
    auto result = helpers::directory::get_file_names(directory_path, ".txt");
    ASSERT_EQ(result, std::vector<std::string>({"test1.txt", "test2.txt"}));
}

TEST(path__get_files_in_directory, get_only_log) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto directory_path = helpers::path::join({current_directory, "test_case_data/helpers/path"});
    auto result = helpers::directory::get_file_names(directory_path, ".log");
    ASSERT_EQ(result, std::vector<std::string>({"agent.log"}));
}