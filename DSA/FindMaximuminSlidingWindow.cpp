// ## Problem Statement
// Find the maximum element in each sliding window of size k in an array.

// ## Task
// - Use deque for optimal solution
// - Time Complexity: O(n)
// - Handle edge cases

// ## Example
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]

#include <deque>
#include <iostream>
#include <vector>
using namespace std;

// Returns a vector of max elements for each sliding window of size k
vector<int> maxSlidingWindow(const vector<int> &nums, int k)
{
    vector<int> res;
    deque<int> dq; // stores indices

    for (int i = 0; i < nums.size(); ++i) {
        // Remove out-of-window indices
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        // Remove smaller values at the back
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
        // Add to result when first window is done
        if (i >= k - 1)
            res.push_back(nums[dq.front()]);
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    for (int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
