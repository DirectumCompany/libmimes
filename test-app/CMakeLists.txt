project(test-app)
add_executable(test-app main.cpp)
target_link_libraries(test-app mimesStatic)
target_include_directories(test-app PUBLIC ../src)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test.txt
        ${CMAKE_CURRENT_BINARY_DIR}/test.txt COPYONLY)
