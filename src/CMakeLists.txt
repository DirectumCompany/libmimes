project(mimes)
set(SOURCES
        exceptions/file_not_found_exception.cpp exceptions/file_not_found_exception.hpp
        helpers/file.cpp helpers/file.hpp
        helpers/path.cpp helpers/path.hpp
        mime/applications_list.hpp
        mime/parser.cpp mime/parser.hpp
        mime/section.hpp
        helpers/string.cpp helpers/string.hpp
        library.cpp library.hpp)
add_library(mimes SHARED ${SOURCES})
add_library(mimesStatic STATIC ${SOURCES})
set_target_properties(mimesStatic PROPERTIES OUTPUT_NAME mimes)