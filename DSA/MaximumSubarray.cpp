// Problem: Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum. This is also known as Kadane's Algorithm problem.​

// Example:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]

// Output: 6

// Explanation: The subarray [4,-1,2,1] has the largest sum of 6.

#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum sum of a contiguous subarray
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];      // Initialize maxSum to first element
    int currentSum = nums[0];  // Initialize currentSum to first element

    // Iterate through the array starting from the second element
    for (int i = 1; i < nums.size(); i++) {
        // If currentSum is negative, start new subarray from nums[i]
        currentSum = max(nums[i], currentSum + nums[i]);
        // Update maxSum if currentSum is greater
        maxSum = max(maxSum, currentSum);
    }
    return maxSum; // Return the largest sum found
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum: " << maxSubArray(nums) << endl;
    return 0;
}
