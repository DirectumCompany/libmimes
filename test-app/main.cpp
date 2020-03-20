#include <iostream>
#include "library.hpp"

void print_mime_type_info(const std::string &mime_type) {
    std::cout << "Mime type: " << mime_type << std::endl;

    auto associations = library::get_mime_type_associations(mime_type);
    std::cout << "Associations from MIME-database: " << std::endl;
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
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Please, specify file directory.";
        return 1;
    }

    auto mime_type = library::get_mime_type(argv[1]);
    print_mime_type_info(mime_type);
    mime_type = library::get_mime_type_by_extension(argv[1]);
    print_mime_type_info(mime_type);

    return 0;
}
