#include <vector>
#include <string>
#include <catch2/catch_all.hpp>

int findNumbersWithEvenNumberOfDigitsSolution0(std::vector<int>& nums) {
    int numbersWithEvenNumberOfDigits = 0;
    std::string strNum;

    for (int num: nums) {
        strNum = std::to_string(num);
        numbersWithEvenNumberOfDigits += (strNum.length() % 2 == 0) ? 1 : 0;
    }

    return numbersWithEvenNumberOfDigits;
}

int findNumbersWithEvenNumberOfDigitsSolution1(std::vector<int>& nums) {
    int numbersWithEvenNumberOfDigits = 0;

    for (int num : nums) {
        int digit = 0;

        while (num > 0) {
            num /= 10;
            digit++;
        }
        numbersWithEvenNumberOfDigits += (digit % 2 == 0) ? 1 : 0;
    }

    return numbersWithEvenNumberOfDigits;
}

TEST_CASE("Find Numbers with Even Number of Digits", "[Data Structures]"){
    std::vector<int> vector1{555,901,482,1771};
    std::vector<int> vector2{12,345,2,6,7896};

    REQUIRE(findNumbersWithEvenNumberOfDigitsSolution0(vector1) == 1);
    REQUIRE(findNumbersWithEvenNumberOfDigitsSolution0(vector2) == 2);

    REQUIRE(findNumbersWithEvenNumberOfDigitsSolution1(vector1) == 1);
    REQUIRE(findNumbersWithEvenNumberOfDigitsSolution1(vector2) == 2);

}


