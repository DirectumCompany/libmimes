project(mimes)
set(SOURCES
        desktop/desktop_entry.hpp
        desktop/desktop_finder.cpp desktop/desktop_finder.hpp
        desktop/desktop_parser.cpp desktop/desktop_parser.hpp
        exceptions/base_exception.cpp exceptions/base_exception.hpp
        exceptions/execute_command_failed_exception.cpp exceptions/execute_command_failed_exception.hpp
        exceptions/not_found_exception.cpp exceptions/not_found_exception.hpp
        exceptions/file_stat_read_exception.cpp exceptions/file_stat_read_exception.hpp
        exceptions/get_command_result_exception.cpp exceptions/get_command_result_exception.hpp
        helpers/command.cpp helpers/command.hpp
        helpers/command_parameter.hpp
        helpers/directory.cpp helpers/directory.hpp
        helpers/environment.cpp helpers/environment.hpp
        helpers/file_mime_utility.cpp helpers/file_mime_utility.hpp
        helpers/file.cpp helpers/file.hpp
        helpers/gio_mime_utility.cpp helpers/gio_mime_utility.hpp
        helpers/mime_utility.cpp helpers/mime_utility.hpp
        helpers/path.cpp helpers/path.hpp helpers/path.ipp
        helpers/string.cpp helpers/string.hpp
        mime/base_parser.cpp mime/base_parser.hpp
        mime/mime_applications.hpp
        mime/mime_applications_file_section.hpp
        mime/mime_applications_parser.hpp mime/mime_applications_parser.cpp
        mime/mime_cache_builder.cpp mime/mime_cache_builder.hpp
        mime/mime_cache_parser.cpp mime/mime_cache_parser.hpp
        mime/mime_cache_reader.cpp mime/mime_cache_reader.hpp
        mime/mime_cache.hpp
        mime/mime_database_reader.cpp mime/mime_database_reader.hpp
        mime/mime_database_file_parser.cpp mime/mime_database_file_parser.hpp
        library.cpp library.hpp)
add_library(mimes SHARED ${SOURCES})
add_library(mimesStatic STATIC ${SOURCES})
set_target_properties(mimesStatic PROPERTIES OUTPUT_NAME mimes POSITION_INDEPENDENT_CODE ON)