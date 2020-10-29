project(ArrayAndString)

add_executable(${PROJECT_NAME} add_binary.cpp diagonal_traverse.cpp dominant_index.cpp find_pivot_index.cpp implement_str_str.cpp longest_common_prefix.cpp pascal_triangle.cpp reverse_string.cpp spiral_matrix.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS_CATCH2} Utils)
