#include "gtest/gtest.h"

#include "library.hpp"

TEST(library__get_mime_type_associations, success) {
    auto associations = library::get_mime_type_associations("text/plain");
}

TEST(library__find_associated_application_from_desktop_files, success) {
    auto associations = library::find_associated_application_from_desktop_files("text/plain");
}