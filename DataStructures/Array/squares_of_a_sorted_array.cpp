#include <vector>
#include <catch2/catch_all.hpp>

std::vector<int> sortedSquares(std::vector<int>& nums) {
    std::vector<int> squares(nums.size());
    int l = 0, r = nums.size() - 1, p = nums.size() - 1;
    while (l <= r)
        squares[p--] = std::pow(nums[(std::abs(nums[l]) > std::abs(nums[r])) ? l++ : r--], 2);
    return squares;
}

TEST_CASE("Squares of a Sorted Array", "[Data Structures]") {
    std::vector<int> vector12{-3, -1, 0};
    REQUIRE_THAT(sortedSquares(vector12), Catch::Matchers::Equals(std::vector<int>{0, 1, 9}));

    std::vector<int> vector0{-3, 0, 2};
    REQUIRE_THAT(sortedSquares(vector0), Catch::Matchers::Equals(std::vector<int>{0, 4, 9}));

    std::vector<int> vector1{-4, -1, 0, 3, 10};
    REQUIRE_THAT(sortedSquares(vector1), Catch::Matchers::Equals(std::vector<int>{0, 1, 9, 16, 100}));

    std::vector<int> vector2{-7, -3, 2, 3, 11};
    REQUIRE_THAT(sortedSquares(vector2), Catch::Matchers::Equals(std::vector<int>{4, 9, 9, 49, 121}));

    std::vector<int> vector3{2, 3, 11};
    REQUIRE_THAT(sortedSquares(vector3), Catch::Matchers::Equals(std::vector<int>{4, 9, 121}));

    std::vector<int> vector4{-1};
    REQUIRE_THAT(sortedSquares(vector4), Catch::Matchers::Equals(std::vector<int>{1}));

    std::vector<int> vector5{-2, 0};
    REQUIRE_THAT(sortedSquares(vector5), Catch::Matchers::Equals(std::vector<int>{0, 4}));
}