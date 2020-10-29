#include <vector>
#include <catch2/catch_all.hpp>

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int curConsecutiveOfOnes = 0;
    int maxConsecutiveOfOnes = 0;

    for(int elem: nums){
        if(elem == 1) {
            curConsecutiveOfOnes++;
        } else {
            if(curConsecutiveOfOnes > maxConsecutiveOfOnes) {
                maxConsecutiveOfOnes = curConsecutiveOfOnes;
            }
            curConsecutiveOfOnes = 0;
        }
    }

    if(curConsecutiveOfOnes > maxConsecutiveOfOnes) {
        maxConsecutiveOfOnes = curConsecutiveOfOnes;
    }

    return maxConsecutiveOfOnes;
}

TEST_CASE("Find Max Consecutive Ones", "[Data Structures]"){
    std::vector vector1{1};
    REQUIRE(findMaxConsecutiveOnes(vector1) == 1);

    std::vector vector2{1,1,0,1,1,1};
    REQUIRE(findMaxConsecutiveOnes(vector2) == 3);
}