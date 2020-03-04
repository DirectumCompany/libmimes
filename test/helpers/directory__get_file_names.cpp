#include <gtest/gtest.h>

#include "helpers/directory.hpp"
#include "helpers/path.hpp"

void prepare_and_check_result(const std::string &directory_path, const std::string &extension,
                              std::vector<std::string> expected_result) {
    std::transform(expected_result.begin(), expected_result.end(), expected_result.begin(),
                   [&directory_path](auto &item) {
                       return helpers::path::join({directory_path, item});
                   });
    auto result = helpers::directory::get_file_names(directory_path, extension);
    ASSERT_EQ(result, expected_result);
}


TEST(directory__get_files_in_directory, get_all) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto directory_path = helpers::path::join({current_directory, "test_case_data/helpers/directory"});
    prepare_and_check_result(directory_path, "",
                             std::vector<std::string>({".hidden", "agent.log", "test1.txt", "test2.txt"}));
}

TEST(directory__get_files_in_directory, get_empty_results) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto directory_path = helpers::path::join({current_directory, "test_case_data/helpers/directory"});
    prepare_and_check_result(directory_path, ".docx", std::vector<std::string>());
}

TEST(directory__get_files_in_directory, get_only_txt) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto directory_path = helpers::path::join({current_directory, "test_case_data/helpers/directory"});
    prepare_and_check_result(directory_path, ".txt", std::vector<std::string>({"test1.txt", "test2.txt"}));
}

TEST(directory__get_files_in_directory, get_only_log) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto directory_path = helpers::path::join({current_directory, "test_case_data/helpers/directory"});
    prepare_and_check_result(directory_path, ".log", std::vector<std::string>({"agent.log"}));
}

TEST(directory__get_files_in_directory, get_only_txt_with_subdirs) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto directory_path = helpers::path::join(
            {current_directory, "test_case_data/helpers/directory_with_subdirectory"});
    prepare_and_check_result(directory_path, ".txt", std::vector<std::string>(
            {"subdir_1/test1.txt", "subdir_2/test2.txt", "test1.txt", "test2.txt"}));
}