project(mimes_test)
find_package(GTest REQUIRED)
set(SOURCES
        run_all_tests.cpp
        helpers/file_is_exists.cpp
        helpers/path__join.cpp helpers/string__split.cpp mime/parser__parse_string.cpp mime/parser__parse_file.cpp helpers/command__get_command_text.cpp helpers/command__execute.cpp helpers/file__get_mime_type.cpp)
add_executable(mimes_test ${SOURCES})
target_include_directories(mimes_test PUBLIC ../src ${GTEST_INCLUDE_DIRS})
target_link_libraries(mimes_test ${GTEST_LIBRARIES} pthread mimes)
enable_testing()
add_custom_command(TARGET mimes_test PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/test_case_data/ $<TARGET_FILE_DIR:mimes_test>/test_case_data)