// Recursive Binary Search in C++
#include <iostream>
#include <vector>
using namespace std;

int binarySearchRecursive(const vector<int>& arr, int left, int right, int target) {
    if (left > right) {
        return -1; // Base case: Target not found
    }

    int mid = left + (right - left) / 2; // To avoid potential overflow

    if (arr[mid] == target) {
        return mid; // Target found
    }
    else if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, right, target); // Search in the right half
    }
    else {
        return binarySearchRecursive(arr, left, mid - 1, target); // Search in the left half
    }
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    int result = binarySearchRecursive(arr, 0, arr.size() - 1, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}