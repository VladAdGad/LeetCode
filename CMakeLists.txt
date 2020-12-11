cmake_minimum_required(VERSION 3.18.3)

project(LeetCode)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME}
        DataStructures/Array/diagonal_traverse.cpp
        DataStructures/Array/duplicate_zeros.cpp
        DataStructures/Array/find_numbers_with_even_number_of_digits.cpp
        DataStructures/Array/find_pivot_index.cpp
        DataStructures/Array/largest_number_at_least_twice_of_others.cpp
        DataStructures/Array/max_consecutive_ones.cpp
        DataStructures/Array/plus_one.cpp
        DataStructures/Array/reverse_string.cpp
        DataStructures/Array/squares_of_a_sorted_array.cpp

        DataStructures/LinkedList/design_singly_linked_list.cpp
        DataStructures/LinkedList/design_doubly_linked_list.cpp
        DataStructures/LinkedList/linked_list_cycle.cpp
        DataStructures/LinkedList/linked_list_cycle_II.cpp
        DataStructures/LinkedList/singly_list_node.cpp

        DataStructures/Queue/circular_queue.cpp

        DataStructures/Stack/daily_temperatures.cpp
        DataStructures/Stack/min_stack.cpp
        DataStructures/Stack/valid_parentheses.cpp

        SearchAlgorithms/BinarySearch/binary_search.cpp
        SearchAlgorithms/BinarySearch/guess_number_higher_or_lower.cpp
        SearchAlgorithms/BinarySearch/search_in_rotated_sorted_array.cpp
        SearchAlgorithms/BinarySearch/sqrt.cpp

        SearchAlgorithms/LinearSearch/linear_search.cpp

        SearchAlgorithms/missing_number.cpp)

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS_CATCH2})
