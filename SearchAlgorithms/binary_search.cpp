#include <catch2/catch_all.hpp>

int binarySearch(std::vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
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

TEST_CASE("Binary Search", "[Search Algorithms]") {
    std::vector<int> emptyVector{};
    REQUIRE(binarySearch(emptyVector, 10) == -1);

    std::vector<int> vectorWithOnlyOneElement{10};
    REQUIRE(binarySearch(vectorWithOnlyOneElement, 10) == 0);

    std::vector<int> vectorForEdgeCases{2, 5};
    REQUIRE(binarySearch(vectorForEdgeCases, 2) == 0);
    REQUIRE(binarySearch(vectorForEdgeCases, 5) == 1);

    std::vector<int> simpleSortedVector{-1, 0, 3, 5, 9, 12};
    REQUIRE(binarySearch(simpleSortedVector, 9) == 4);

}
