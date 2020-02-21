#include <gtest/gtest.h>

#include "mime/mime_applications.hpp"
#include "mime/mime_cache_builder.hpp"

TEST(mime_cache_builder__from_mime_applications, only_defaults) {
    mime::mime_applications applications;
    applications.default_applications = {
            {"text/plain", {"gedit", "notepad"}}
    };
    auto result = mime::mime_cache_builder::from_mime_applications(applications);
    ASSERT_EQ(result->associations, applications.default_applications);
}

TEST(mime_cache_builder__from_mime_applications, remove_one_application) {
    mime::mime_applications applications;
    applications.default_applications = {
            {"text/plain", {"gedit", "notepad"}}
    };
    applications.removed_associations = {
            {"text/plain", {"gedit"}}
    };
    auto result = mime::mime_cache_builder::from_mime_applications(applications);
    std::map<std::string, std::vector<std::string>> expected_result = {
            {"text/plain", {"notepad"}}
    };
    ASSERT_EQ(result->associations, expected_result);
}

TEST(mime_cache_builder__from_mime_applications, remove_all_applications) {
    mime::mime_applications applications;
    applications.default_applications = {
            {"text/plain", {"gedit", "notepad"}}
    };
    applications.removed_associations = {
            {"text/plain", {"gedit", "notepad"}}
    };
    auto result = mime::mime_cache_builder::from_mime_applications(applications);
    ASSERT_TRUE(result->associations.empty());
}

TEST(mime_cache_builder__from_mime_applications, add_application) {
    mime::mime_applications applications;
    applications.default_applications = {
            {"text/plain", {"gedit"}}
    };
    applications.added_associations = {
            {"text/plain", {"notepad"}}
    };
    auto result = mime::mime_cache_builder::from_mime_applications(applications);
    std::map<std::string, std::vector<std::string>> expected_result = {
            {"text/plain", {"notepad", "gedit"}}
    };
    ASSERT_EQ(result->associations, expected_result);
}

TEST(mime_cache_builder__from_mime_applications, all_sections) {
    mime::mime_applications applications;
    applications.default_applications = {
            {"text/plain", {"gedit", "notepad"}}
    };
    applications.removed_associations = {
            {"text/plain", {"gedit", "notepad"}}
    };
    applications.added_associations = {
            {"text/plain", {"vscode"}},
            {"pdf", {"ocular"}}
    };
    auto result = mime::mime_cache_builder::from_mime_applications(applications);
    std::map<std::string, std::vector<std::string>> expected_result = {
            {"text/plain", {"vscode"}},
            {"pdf", {"ocular"}}
    };
    ASSERT_EQ(result->associations, expected_result);
}