project('LeetCode', 'cpp')

executable = executable(
    meson.project_name(),
    'DataStructures/Array/duplicate_zeros.cpp',
    'DataStructures/Array/find_numbers_with_even_number_of_digits.cpp',
    'DataStructures/Array/find_pivot_index.cpp',
    'DataStructures/Array/largest_number_at_least_twice_of_others.cpp',
    'DataStructures/Array/max_consecutive_ones.cpp',
    'DataStructures/Array/squares_of_a_sorted_array.cpp',
    'DataStructures/LinkedList/singly_linked_list.cpp',
    'DataStructures/Queue/circular_queue.cpp',
    'DataStructures/Stack/daily_temperatures.cpp',
    'DataStructures/Stack/min_stack.cpp',
    'DataStructures/Stack/valid_parentheses.cpp',

    'SearchAlgorithms/BinarySearch/binary_search.cpp',
    'SearchAlgorithms/BinarySearch/guess_number_higher_or_lower.cpp',
    'SearchAlgorithms/BinarySearch/search_in_rotated_sorted_array.cpp',
    'SearchAlgorithms/BinarySearch/sqrt.cpp',
    'SearchAlgorithms/LinearSearch/linear_search.cpp',
    'SearchAlgorithms/missing_number.cpp',
    dependencies:
    [dependency('catch2')]
                        )
test(meson.project_name(), executable)
