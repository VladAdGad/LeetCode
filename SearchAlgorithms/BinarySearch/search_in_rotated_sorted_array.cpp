#include <iostream>
#include <catch2/catch_all.hpp>

int findIndexOfRotation(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    if (nums[left] < nums[right]) {
        return 0;
    }

    while (left <= right) {
        int mid = left + ((right - left) / 2);
        if (nums[mid] > nums[mid + 1]) {
            return mid + 1;
        }
        if (nums[mid] < nums[0]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return 0;
}

int binarySearch(std::vector<int>& nums, int left, int right, int target) {
    int mid;

    while (left <= right) {
        mid = left + ((right - left) / 2);
        if (target == nums[mid]) {
            return mid;
        } else if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int search(std::vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    if (nums.size() == 1) {
        return nums[0] == target ? 0 : -1;
    }

    int indexOfRotation = findIndexOfRotation(nums);

    if (indexOfRotation == 0) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    } else {
        if (target >= nums[0]) {
            return binarySearch(nums, 0, indexOfRotation - 1, target);
        } else {
            return binarySearch(nums, indexOfRotation, nums.size() - 1, target);
        }
    }
}

TEST_CASE("") {
    std::vector<int> vector;

    vector = {0, 1, 2, 4, 5, 6, 7};
    REQUIRE(search(vector, 0) == 0);

    vector = {4, 5, 6, 7, 0, 1, 2};
    REQUIRE(search(vector, 0) == 4);

    vector = {1};
    REQUIRE(search(vector, 1) == 0);

    vector = {3, 1};
    REQUIRE(search(vector, 1) == 1);
}