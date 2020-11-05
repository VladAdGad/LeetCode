project(SearchAlgorithms)

add_executable(${PROJECT_NAME}
        binary_search.cpp
        guess_number_higher_or_lower.cpp
        linear_search.cpp
        missing_number.cpp
        search_in_rotated_sorted_array.cpp
        sqrt.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS_CATCH2})
