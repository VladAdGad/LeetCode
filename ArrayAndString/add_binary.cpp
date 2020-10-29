#include <string>
#include <catch2/catch_all.hpp>

std::string addBinary(std::string a, std::string b) {
    std::string result;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry == 1) {

        carry += i >= 0 ? a[i] - '0' : 0;
        carry += j >= 0 ? b[j] - '0' : 0;

        result = char(carry % 2 + '0') + result;

        carry /= 2;

        i--;
        j--;
    }

    return result;
}

TEST_CASE("Add Binary", "[Array And String]") {
    REQUIRE(addBinary("11", "1") == "100");
}
