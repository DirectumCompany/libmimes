#include "gtest/gtest.h"

#include "library.hpp"

TEST(library__get_mime_type_associations, success) {
    auto associations = get_mime_type_associations("text/plain");
    associations = get_mime_type_associations("application/pdf");
}