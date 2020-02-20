#include <iostream>
#include "library.hpp"

int main() {
    auto mime_type = get_mime_type("test.txt");
    auto associations = get_mime_type_associations(mime_type);
    std::cout << mime_type << ": " << associations[0] << std::endl;
}
