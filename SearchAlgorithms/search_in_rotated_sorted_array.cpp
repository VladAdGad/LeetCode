#include <iostream>
#include <catch2/catch_all.hpp>
#include "binary_search.h"

int findIndexOfRotation(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    int mid1;
    int mid2;

    while (left <= right) {
        mid1 = left + ((right - left) / 2);
        mid2 = mid1 + ((right - mid1) / 2);

        if (mid1 < mid2) {
            left = mid1 + 1;
        } else if (mid1 >= mid2) {
            right = mid2 - 1;
        }
    }

    return mid1;
}

int search(std::vector<int>& nums, int target) {
    int indexOfRotation = findIndexOfRotation(nums);

    if (nums.size() == 0) {
        return -1;
    }

    int result1 = -1;
    int result2 = -1;
    if (nums.size() == 1) {
        std::vector<int> split_vector1(nums.begin(), nums.end() - (nums.size() - 1));
        result1 = binarySearch(split_vector1, target);

        if (result1 != -1) {
            return result1;
        }
    } else {
        std::vector<int> split_vector1(nums.begin(), nums.end() - ((nums.size() - 1) - indexOfRotation));
        std::vector<int> split_vector2;
        if (indexOfRotation == 0) {
            split_vector2 = std::vector<int>(nums.begin() + (indexOfRotation + 1), nums.end());
        } else {
            split_vector2 = std::vector<int>(nums.begin() + indexOfRotation, nums.end());
        }
        result1 = binarySearch(split_vector1, target);
        result2 = binarySearch(split_vector2, target);

        if (result1 != -1) {
            return result1;
        }
        if (result2 != -1) {
            return split_vector1.size() + result2;
        }
    }

    return -1;
}

TEST_CASE("") {
    std::vector<int> vector1{4, 5, 6, 7, 0, 1, 2};
    REQUIRE(search(vector1, 0) == 4);

    std::vector<int> vector2{1};
    REQUIRE(search(vector2, 1) == 0);

    std::vector<int> vector3{3, 1};
    REQUIRE(search(vector3, 1) == 1);
}