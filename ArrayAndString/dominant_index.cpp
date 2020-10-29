#include <vector>
#include <cstdio>

int dominantIndex(std::vector<int> &nums) {
    int largest1 = 0, pivotLargest1 = 0;
    int largest2 = 0;
    size_t numsSize = nums.size();

    for (size_t i = 2; i < numsSize; ++i) {
        if (largest1 < nums[i]) {
            largest2 = largest1;
            largest1 = nums[i];
            pivotLargest1 = i;
        }
        if (largest2 < nums[i] && largest1 != nums[i]) {
            largest2 = nums[i];
        }
    }

    if (largest1 / 2.0 >= largest2) {
        return pivotLargest1;
    }

    return -1;
}

//int main() {
//
//    std::vector<int> v1{3, 6, 1, 0};
//    std::vector<int> v2{1, 2, 3, 4};
//
//    printf("%d\n", dominantIndex(v1));
//    printf("%d\n", dominantIndex(v2));
//
//    return 0;
//}
