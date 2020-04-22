#include <gtest/gtest.h>

#include "helpers/file.hpp"


void check_mime_type(const std::string &source, const std::string &expected) {
    auto result = helpers::file::extract_mime_type(source);
    ASSERT_EQ(result, expected);
}

TEST(file__extract_mime_type, alt9_application_vnd_oasis_opendocument_text) {
    check_mime_type("document: application/vnd.oasis.opendocument.text",
                    "application/vnd.oasis.opendocument.text");
}

TEST(file__extract_mime_type, application_vnd_oasis_opendocument_text) {
    check_mime_type("document: application/vnd.oasis.opendocument.text; charset=binary",
                    "application/vnd.oasis.opendocument.text");
}

TEST(file__extract_mime_type, application_rss_xml) {
    check_mime_type("document: application/rss+xml; charset=binary",
                    "application/rss+xml");
}

TEST(file__extract_mime_type, application_vnd_ms_excel_sheet_binary_macroEnabled_12) {
    check_mime_type("document: application/vnd.ms-excel.sheet.binary.macroEnabled.12; charset=binary",
                    "application/vnd.ms-excel.sheet.binary.macroEnabled.12");
}

TEST(file__extract_mime_type, application_xhtml_xml) {
    check_mime_type("document: application/xhtml_xml; charset=binary",
                    "application/xhtml_xml");
}

TEST(file__extract_mime_type, x_scheme_handler_apt) {
    check_mime_type("document: x-scheme-handler/apt; charset=binary",
                    "x-scheme-handler/apt");
}

