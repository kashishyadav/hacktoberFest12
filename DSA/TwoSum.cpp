// Problem: Given an array of integers nums and an integer target, return the indices of the two numbers in the array that add up to the target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.​

// Example:

// Input: nums = [2][7], target = 9

// Output: [1]

// Explanation: Because nums + nums[1] == 9, we return [1]


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to find indices of two numbers that add up to the target
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map; // Stores number and its index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Find the complement
        // Check if complement exists in the map
        if (num_map.find(complement) != num_map.end()) {
            // Return indices if found
            return {num_map[complement], i};
        }
        // Store the current number with its index
        num_map[nums[i]] = i;
    }
    // Return empty if no solution found
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    // Output the result
    if (!result.empty())
        cout << result[0] << " " << result[1] << endl;
    else
        cout << "No solution found" << endl;
    return 0;
}
