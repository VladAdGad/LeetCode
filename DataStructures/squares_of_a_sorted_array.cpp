#include <vector>
#include <catch2/catch_all.hpp>

int findIndexOfLastNegativeNumber(std::vector<int> nums) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = -1;

    while (left <= right) {
        mid = left + ((right - left) / 2);

        if (nums[mid] >= 0) {
            right = mid - 1;
        } else if (nums[mid + 1] < 0) {
            left = mid + 1;
        } else {
            return mid;
        }

    }

    if (nums[mid] < 0) {
        return mid;
    } else {
        return -1;
    }
}

std::vector<int> sortedSquares(std::vector<int>& nums) {
    if (nums.size() == 1) {
        nums[0] *= nums[0];
        return nums;
    }

    int amountOfNegativeNumbers = findIndexOfLastNegativeNumber(nums) + 1;

    while (amountOfNegativeNumbers != 0) {
        int target = std::abs(nums[0]);

        bool isInserted = false;
        if (target >= nums[nums.size() - 1]){
            nums.insert(nums.begin() + nums.size(), target);
            isInserted = true;
            nums.erase(nums.begin());
            amountOfNegativeNumbers--;
        }

        for (int indexInPositivePart = amountOfNegativeNumbers; !isInserted; indexInPositivePart++) {
            if (target <= nums[indexInPositivePart]) {
                nums.insert(nums.begin() + indexInPositivePart, target);
                nums.erase(nums.begin());
                amountOfNegativeNumbers--;
                isInserted = true;
            }
        }
    }

    std::vector<int>::iterator it = nums.begin();
    for (int i = 0; it != nums.end(); it++, i++) {
        *it *= *it;
    }

    return nums;
}

TEST_CASE("Squares of a Sorted Array", "[Data Structures]") {
//    std::vector<int> vector1{-4, -1, 0, 3, 10};
//    REQUIRE_THAT(sortedSquares(vector1), Catch::Matchers::Equals(std::vector<int>{0, 1, 9, 16, 100}));
////
//    std::vector<int> vector2{-7, -3, 2, 3, 11};
//    REQUIRE_THAT(sortedSquares(vector2), Catch::Matchers::Equals(std::vector<int>{4, 9, 9, 49, 121}));
////
//    std::vector<int> vector3{2, 3, 11};
//    REQUIRE_THAT(sortedSquares(vector3), Catch::Matchers::Equals(std::vector<int>{4, 9, 121}));
////
//    std::vector<int> vector4{-1};
//    REQUIRE_THAT(sortedSquares(vector4), Catch::Matchers::Equals(std::vector<int>{1}));
//    std::vector<int> vector5{-1, -2, -5, -4, -9, -10, 4};
//    int a = findIndexOfLastNegativeNumber(vector5);
    std::vector<int> vector5{-2, 0};
    REQUIRE_THAT(sortedSquares(vector5), Catch::Matchers::Equals(std::vector<int>{0, 4}));
}