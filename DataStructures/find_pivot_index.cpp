#include <catch2/catch_all.hpp>

int findPivotIndex(std::vector<int>& nums) {
    int sum = 0;
    int leftSum = 0;
    int rightSum = 0;

    for (auto num : nums) {
        sum += num;
    }

    rightSum = sum;
    for (int i = 0; i < nums.size(); ++i) {
        rightSum -= nums[i];
        if(leftSum == rightSum) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}

TEST_CASE("Find Pivot Index", "[Data Structure]") {

    std::vector<int> nums{1, 7, 3, 6, 5, 6};
    REQUIRE(findPivotIndex(nums) == 3);
}
