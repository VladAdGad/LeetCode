#include <catch2/catch_all.hpp>

int mySqrt(int x) {
    int left = 2;
    int right = x / 2;
    int mid = 0;
    int approx = 0;

    if (x < 2){
        return x;
    }

    while (left <= right){
        mid = left + ((right - left) / 2);
        approx = mid * mid;

        if (approx < x){
            left = mid + 1;
        } else if (approx > x){
            right = mid - 1;
        } else {
            return mid;
        }
    }

    return right;
}

TEST_CASE("Sqrt", "[Search Algorithms]") {
    REQUIRE(mySqrt(4) == 2);
    REQUIRE(mySqrt(8) == 2);
    REQUIRE(mySqrt(16) == 4);
    REQUIRE(mySqrt(32) == 5);
}
