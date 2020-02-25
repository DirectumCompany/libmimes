#include <gtest/gtest.h>
#include <map>
#include <memory>
#include <string>

#include "helpers/path.hpp"
#include "mime/mime_applications_parser.hpp"

void check_associations(const std::string &example_file_name,
                        const std::map<std::string, std::vector<std::string>> &expected_added_associations,
                        const std::map<std::string, std::vector<std::string>> &expected_removed_associations,
                        const std::map<std::string, std::vector<std::string>> &expected_default_applications) {
    auto registered_associations = std::shared_ptr<mime::mime_applications>(
            mime::mime_applications_parser::parse_file(example_file_name));
    ASSERT_EQ(registered_associations->added_associations, expected_added_associations);
    ASSERT_EQ(registered_associations->removed_associations, expected_removed_associations);
    ASSERT_EQ(registered_associations->default_applications, expected_default_applications);
}

TEST(mime_applications_parser__parse, only_defaults) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto example_file_name = helpers::path::join({current_directory, "/test_case_data/mime/parser/only_defaults.list"});
    std::map<std::string, std::vector<std::string>> default_applications = {
            {"application/csv",                                                         {"libreoffice-calc.desktop"}},
            {"application/vnd.oasis.opendocument.database",                             {"libreoffice-base.desktop"}},
            {"application/vnd.openxmlformats-officedocument.wordprocessingml.document", {"libreoffice-writer.desktop"}},
    };
    check_associations(example_file_name, {}, {}, default_applications);
}

TEST(mime_applications_parser__parse, only_added) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto example_file_name = helpers::path::join({current_directory, "/test_case_data/mime/parser/only_added.list"});
    std::map<std::string, std::vector<std::string>> added_associations = {
            {"application/csv",                                                         {"libreoffice-calc.desktop"}},
            {"application/vnd.oasis.opendocument.database",                             {"libreoffice-base.desktop"}},
            {"application/vnd.openxmlformats-officedocument.wordprocessingml.document", {"libreoffice-writer.desktop"}},
    };
    check_associations(example_file_name, added_associations, {}, {});
}

TEST(mime_applications_parser__parse, only_removed) {
    auto current_directory = helpers::path::get_current_working_directory();
    auto example_file_name = helpers::path::join({current_directory, "/test_case_data/mime/parser/only_removed.list"});
    std::map<std::string, std::vector<std::string>> removed_associations = {
            {"application/csv",                                                         {"libreoffice-calc.desktop"}},
            {"application/vnd.oasis.opendocument.database",                             {"libreoffice-base.desktop"}},
            {"application/vnd.openxmlformats-officedocument.wordprocessingml.document", {"libreoffice-writer.desktop"}},
    };
    check_associations(example_file_name, {}, removed_associations, {});
}
