#include <catch2/catch_all.hpp>

std::string addBinary(std::string a, std::string b) {
    std::string result;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while(i >= 0 || j >= 0 || carry == 1) {

        carry += i >= 0 ? a[i--] - '0' : 0;
        carry += j >= 0 ? b[j--] - '0' : 0;

        result = char(carry % 2 + '0') + result;

        carry /= 2;
    }

    return result;
}

TEST_CASE("Add Binary", "[Data Structures]") {
    std::string a, b;

    a = "11";
    b = "1";
    REQUIRE(addBinary(a, b) == "100");

    a = "1010";
    b = "1011";
    REQUIRE(addBinary(a, b) == "10101");

}
