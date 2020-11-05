project(DataStructures)

add_executable(${PROJECT_NAME}
        circular_queue.cpp
        duplicate_zeros.cpp
        find_numbers_with_even_number_of_digits.cpp
        find_pivot_index.cpp
        min_stack.cpp
        singly_linked_list.cpp
        max_consecutive_ones.cpp
        squares_of_a_sorted_array.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS_CATCH2})
