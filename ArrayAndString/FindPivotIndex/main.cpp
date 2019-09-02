#include <iostream>
#include <vector>
#include <numeric>

int pivotIndex(std::vector<int> &nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0, numsSize = nums.size();
    for (int pivot = 0; pivot < numsSize; ++pivot) {
        if (leftSum == sum - nums[pivot] - leftSum) return pivot;
        leftSum += nums[pivot];
    }
    return -1;
}

int main() {
    std::vector<int> nums{1, 7, 3, 6, 5, 6};

    printf("%d", pivotIndex(nums));

    return 0;
}
