#include <gtest/gtest.h>

#include "helpers/path.hpp"
#include "mime/mime_database_file_parser.hpp"

TEST(mime_database_file_parser__parse_file, mime_type) {
    auto file_path = helpers::path::join({helpers::path::get_current_working_directory(),
                                          "test_case_data/mime/parser/mime.xml"});
    auto result = mime::mime_database_file_parser::parse_file(file_path);
    std::map<std::string, std::string> expected_result({{"ez", "application/andrew-inset"}});
    ASSERT_EQ(result, expected_result);
}

TEST(mime_database_file_parser__parse_file, vnd_sun_xml_draw) {
    auto file_path = helpers::path::join({helpers::path::get_current_working_directory(),
                                          "test_case_data/mime/parser/mime2.xml"});
    auto result = mime::mime_database_file_parser::parse_file(file_path);
    std::map<std::string, std::string> expected_result({{"sxd", "application/vnd.sun.xml.draw"}});
    ASSERT_EQ(result, expected_result);
}