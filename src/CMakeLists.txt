project(mimes)
set(SOURCES
        exceptions/base_exception.cpp exceptions/base_exception.hpp
        exceptions/execute_command_failed_exception.cpp exceptions/execute_command_failed_exception.hpp
        exceptions/file_not_found_exception.cpp exceptions/file_not_found_exception.hpp
        exceptions/get_command_result_exception.cpp exceptions/get_command_result_exception.hpp
        helpers/command.cpp helpers/command.hpp
        helpers/file.cpp helpers/file.hpp
        helpers/path.cpp helpers/path.hpp
        helpers/string.cpp helpers/string.hpp
        mime/mime_cache_parser.cpp mime/mime_cache_parser.hpp
        mime/mime_cache.hpp
        library.cpp library.hpp helpers/environment.cpp helpers/environment.hpp mime/mime_cache_reader.cpp mime/mime_cache_reader.hpp exceptions/file_stat_read_exception.cpp exceptions/file_stat_read_exception.hpp mime/base_parser.cpp mime/base_parser.hpp mime/mime_applications.hpp mime/mime_applications_parser.cpp mime/mime_applications_parser.hpp mime/mime_applications_file_section.hpp)
add_library(mimes SHARED ${SOURCES})
add_library(mimesStatic STATIC ${SOURCES})
set_target_properties(mimesStatic PROPERTIES OUTPUT_NAME mimes)