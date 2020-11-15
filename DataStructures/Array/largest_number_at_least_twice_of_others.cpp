#include <catch2/catch_all.hpp>

int dominantIndex(std::vector<int>& nums) {
    int indexMax = 0;
    int prevIndexMax = 0;

    for(int curNum : nums) {
        if(curNum >= nums[indexMax]) {
            nums[prevIndexMax] = nums[indexMax];
            nums[indexMax] = curNum;
        }
    }

    return nums[prevIndexMax] >= nums[indexMax] / 2 ? indexMax : -1;
}
