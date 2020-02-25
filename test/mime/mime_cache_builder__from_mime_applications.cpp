#include <gtest/gtest.h>
#include <memory>

#include "mime/mime_applications.hpp"
#include "mime/mime_cache_builder.hpp"

TEST(mime_cache_builder__from_mime_applications, only_defaults) {
    auto applications = new mime::mime_applications();
    applications->default_applications = {
            {"text/plain", {"gedit", "notepad"}}
    };
    auto result = std::shared_ptr<mime::mime_cache>(mime::mime_cache_builder::from_mime_applications(applications));
    auto expected_result = applications->default_applications;
    delete applications;
    ASSERT_EQ(result->associations, expected_result);
}

TEST(mime_cache_builder__from_mime_applications, remove_one_application) {
    auto applications = new mime::mime_applications();
    applications->default_applications = {
            {"text/plain", {"gedit", "notepad"}}
    };
    applications->removed_associations = {
            {"text/plain", {"gedit"}}
    };
    auto result = std::shared_ptr<mime::mime_cache>(mime::mime_cache_builder::from_mime_applications(applications));
    delete applications;
    std::map<std::string, std::vector<std::string>> expected_result = {
            {"text/plain", {"notepad"}}
    };
    ASSERT_EQ(result->associations, expected_result);
}

TEST(mime_cache_builder__from_mime_applications, remove_all_applications) {
    auto applications = new mime::mime_applications();
    applications->default_applications = {
            {"text/plain", {"gedit", "notepad"}}
    };
    applications->removed_associations = {
            {"text/plain", {"gedit", "notepad"}}
    };
    auto result = std::shared_ptr<mime::mime_cache>(mime::mime_cache_builder::from_mime_applications(applications));
    delete applications;
    ASSERT_TRUE(result->associations.empty());
}

TEST(mime_cache_builder__from_mime_applications, add_application) {
    auto applications = new mime::mime_applications();
    applications->default_applications = {
            {"text/plain", {"gedit"}}
    };
    applications->added_associations = {
            {"text/plain", {"notepad"}}
    };
    auto result = std::shared_ptr<mime::mime_cache>(mime::mime_cache_builder::from_mime_applications(applications));
    delete applications;
    std::map<std::string, std::vector<std::string>> expected_result = {
            {"text/plain", {"notepad", "gedit"}}
    };
    ASSERT_EQ(result->associations, expected_result);
}

TEST(mime_cache_builder__from_mime_applications, all_sections) {
    auto applications = new mime::mime_applications();
    applications->default_applications = {
            {"text/plain", {"gedit", "notepad"}}
    };
    applications->removed_associations = {
            {"text/plain", {"gedit", "notepad"}}
    };
    applications->added_associations = {
            {"text/plain", {"vscode"}},
            {"pdf", {"ocular"}}
    };
    auto result = std::shared_ptr<mime::mime_cache>(mime::mime_cache_builder::from_mime_applications(applications));
    delete applications;
    std::map<std::string, std::vector<std::string>> expected_result = {
            {"text/plain", {"vscode"}},
            {"pdf", {"ocular"}}
    };
    ASSERT_EQ(result->associations, expected_result);
}