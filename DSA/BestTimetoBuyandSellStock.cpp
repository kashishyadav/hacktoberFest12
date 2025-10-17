// Problem: You are given an array of prices where prices[i] is the price of a given stock on the i-th day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to calculate the maximum profit from a single buy-sell transaction
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX; // Track the minimum price so far
    int maxProfit = 0;      // Track the maximum profit so far

    // Iterate through each day's price
    for (int price : prices) {
        // Update minPrice if current price is lower
        if (price < minPrice)
            minPrice = price;
        // Calculate profit if selling today, update maxProfit if it's higher
        else if (price - minPrice > maxProfit)
            maxProfit = price - minPrice;
    }
    return maxProfit; // Return the best profit found
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit: " << maxProfit(prices) << endl;
    return 0;
}
