#include <gtest/gtest.h>

#include "helpers/file.hpp"
#include "helpers/path.hpp"

TEST(file__get_mime_type, text_plain) {
    auto file_path = helpers::path::join(helpers::path::get_current_working_directory(),
                                          "test_case_data/helpers/file");
    ASSERT_EQ(helpers::file::get_mime_type(file_path), "text/plain");
}

TEST(file__get_mime_type, application_gzip) {
    auto file_path = helpers::path::join(helpers::path::get_current_working_directory(),
                                          "test_case_data/helpers/file.tar.gz");
    ASSERT_EQ(helpers::file::get_mime_type(file_path), "application/x-compressed-tar");
}

TEST(file__get_mime_type, docx) {
    auto file_path = helpers::path::join(helpers::path::get_current_working_directory(),
                                          "test_case_data/helpers/file.docx");
    ASSERT_EQ(helpers::file::get_mime_type(file_path),
            "application/vnd.openxmlformats-officedocument.wordprocessingml.document");
}

TEST(file__get_mime_type, filename_with_spaces) {
    auto file_path = helpers::path::join(helpers::path::get_current_working_directory(),
                                          "test_case_data", "helpers", "some file");
    ASSERT_EQ(helpers::file::get_mime_type(file_path), "text/plain");
}