#include <catch2/catch_all.hpp>

int dominantIndex(std::vector<int>& nums) {
    if (nums.size() == 1) {
        return 0;
    }

    int largest = -1;
    int prevLargest = -1;
    if (nums[0] > nums[1]) {
        largest = 0;
        prevLargest = 1;
    } else {
        largest = 1;
        prevLargest = 0;
    }

    for (int i = 2; i < nums.size(); ++i) {
        if (nums[i] > nums[largest]) {
            prevLargest = largest;
            largest = i;
        } else if (nums[i] > nums[prevLargest]) {
            prevLargest = i;
        }
    }

    return nums[largest] >= nums[prevLargest] * 2 ? largest : -1;
}

TEST_CASE("Largest Number At Least Twice of Others", "[Data Structures]") {
    std::vector<int> vector;

    vector = {3, 6, 1, 0};
    REQUIRE(dominantIndex(vector) == 1);

    vector = {1, 2, 3, 4};
    REQUIRE(dominantIndex(vector) == -1);

    vector = {1};
    REQUIRE(dominantIndex(vector) == 0);

    vector = {1, 0};
    REQUIRE(dominantIndex(vector) == 0);

    vector = {0, 0, 3, 2};
    REQUIRE(dominantIndex(vector) == -1);

    vector = {0, 3, 1, 2};
    REQUIRE(dominantIndex(vector) == -1);
}
