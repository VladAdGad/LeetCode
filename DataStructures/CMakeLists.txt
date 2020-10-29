project(DataStructures)

add_executable(${PROJECT_NAME}
        max_consecutive_ones.cpp
        find_numbers_with_even_number_of_digits.cpp
        squares_of_a_sorted_array.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS_CATCH2})
