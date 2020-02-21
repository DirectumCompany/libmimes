#include <iostream>
#include "library.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Please, specify file path.";
        return 1;
    }

    auto mime_type = library::get_mime_type(argv[1]);
    std::cout << "Mime type: " << mime_type << std::endl;

    auto associations = library::get_mime_type_associations(mime_type);
    std::cout << "Mime apps: " << std::endl;
    if (associations.empty()) {
        std::cout << "\tAssociations not found" << std::endl;
    } else {
        for (const auto &application: associations) {
            std::cout << "\t" << application << std::endl;
        }
    }

    associations = library::find_associated_application_from_desktop_files(mime_type);
    std::cout << "Desktop entries: " << std::endl;
    if (associations.empty()) {
        std::cout << "\tAssociations not found" << std::endl;
    } else {
        for (const auto &application: associations) {
            std::cout << "\t" << application << std::endl;
        }
    }

    return 0;
}
