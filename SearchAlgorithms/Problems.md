# Binary Search
Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. 
If target exists, then return its index, otherwise return -1.

**Example 1:**
```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```
**Example 2:**
```
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```
**Note:**
1. You may assume that all elements in nums are unique.
2. n will be in the range [1, 10000].
3. The value of each element in nums will be in the range [-9999, 9999].

# Guess Number
We are playing the Guess Game. The game is as follows:
I pick a number from **1** to **n**. You have to guess which number I picked.
Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
You call a pre-defined API int **guess(int num)**, which returns 3 possible results:

- **-1**: The number I picked is lower than your guess (i.e. **pick < num**).
- **1**: The number I picked is higher than your guess (i.e. **pick > num**).
- **0**: The number I picked is equal to your guess (i.e. **pick == num**).

Return the number that I picked.

**Example 1:**
```
Input: n = 10, pick = 6
Output: 6
```
**Example 2:**
```
Input: n = 1, pick = 1
Output: 1
```
**Example 3:**
```
Input: n = 2, pick = 1
Output: 1
```
**Example 4:**
```
Input: n = 2, pick = 2
Output: 2
```
**Constraints:**
* **1 <= n <= 231 - 1**
* **1 <= pick <= n**

# Linear Search
Given an array Arr of N elements and a integer K. Your task is to return the position of first occurence of K in the given array.
Note: Position of first element is considered as 1.

**Example 1:**
```
N = 5, K = 16
Arr[] = {9, 7, 2, 16, 4}
Output: 4
Explanation: K = 16 is found in the
given array at position 4.
```
**Example 2:**
```
N = 7, K = 98
Arr[] = {1, 22, 57, 47, 34, 18, 66}
Output: -1
Explanation: K = 98 isn't found in
the given array.
```
Your Task:
Complete the function linearSearch() which takes an array arr, two integers n and k, as input parameters and returns an integer denoting the answer. 
Return -1 if the number is not found in array. You don't to print answer or take inputs.

- Expected Time Complexity: O(N)
- Expected Auxiliary Space: O(1)
- Constraints:
    - 1 <= N <= 106
    - 1 <= K <= 106
    - 1 <= Arr[i] <= 106

# Missing Number
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

**Example 1:**
```
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```
**Example 2:**
```
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
```
**Example 3:**
```
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
```
**Example 4:**
```
Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 1 is the missing number in the range since it does not appear in nums.
```
**Constraints**:
- **n == nums.length**
- **1 <= n <= 104**
- **0 <= nums[i] <= n**
- All the numbers of **nums** are **unique**.

# Search in Rotated Sorted Array
You are given an integer array **nums** sorted in ascending order, and an integer **target**.
Suppose that **nums** is rotated at some pivot unknown to you beforehand (i.e., **[0,1,2,4,5,6,7]** might become **[4,5,6,7,0,1,2]**).
If **target** is found in the array return its index, otherwise, return **-1**.

**Example 1:**
```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```
**Example 2:**
```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```
**Example 3:**
```
Input: nums = [1], target = 0
Output: -1
```
**Constraints:**
* **1 <= nums.length <= 5000**
* **-10^4 <= nums[i] <= 10^4**
* All values of **nums** are **unique**.
* **nums** is guranteed to be rotated at some pivot.
* **-10^4 <= target <= 10^4**

# Sqrt
Implement **int sqrt(int x)**.
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

**Example 1:**
```
Input: 4
Output: 2
```
**Example 2:**
```
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
```
* **Hint #1**
Try exploring all integers. (Credits: @annujoshi)
* **Hint #2**
Use the sorted property of integers to reduced the search space. (Credits: @annujoshi)