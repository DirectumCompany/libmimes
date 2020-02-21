#include <iostream>
#include "library.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Please, specify file path.";
        return 1;
    }

    auto mime_type = get_mime_type(argv[1]);
    auto associations = get_mime_type_associations(mime_type);
    std::cout << mime_type << ": " << (associations.empty() ? "Association not found" : associations[0]) << std::endl;
    return 0;
}
