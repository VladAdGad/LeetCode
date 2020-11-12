#include <vector>
#include <catch2/catch_all.hpp>

std::vector<int> duplicateZeros(std::vector<int> nums) {
    int zeros = 0, originalSize = nums.size();
    for (int num: nums) {
        if (num == 0) {
            ++zeros;
        }
    }
    for (int i = originalSize - 1, j = originalSize - 1 + zeros; i >= 0; --i, --j) {
        if (nums[i] == 0) {
            if (j < originalSize) {
                nums[j] = 0;
            }
            --j;
        }
        if (j < originalSize) {
            nums[j] = nums[i];
        }
    }

    return nums;
}

TEST_CASE("Duplicate Zeros", "[Data Structures]") {
    std::vector<int> vector{1, 0, 2, 3, 0, 4, 5, 0};
    REQUIRE_THAT(duplicateZeros(vector), Catch::Matchers::Equals(std::vector<int>{1, 0, 0, 2, 3, 0, 0, 4}));
}
