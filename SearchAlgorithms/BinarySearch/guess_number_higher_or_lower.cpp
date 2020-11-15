#include <catch2/catch_all.hpp>

class Guess {
public:
    int pick;

    int guess(int n) {
        if(n == pick) {
            return 0;
        } else if(n < pick) {
            return -1;
        } else {
            return 1;
        }
    }
};


int guessNumber(int n) {
    int left = 0;
    int right = n;
    int mid = 0;
    int res = 0;

    while (left <= right) {
        mid = left + ((right - left) / 2);
//        res = guess(mid);

        if (res == 0) {
            return mid;
        } else if (res == -1) {
            right = mid + res;
        } else {
            left = mid + res;
        }
    }
    return -1;
}

TEST_CASE("Guess Number", "[Search Algorithms]") {
//    REQUIRE(guessNumber(10) == 6);
}
