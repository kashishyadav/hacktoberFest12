// Given three items with weights 10, 20, and 30, and values 60, 100, and 120, find the maximum value you can place in a knapsack of capacity 50 units if you can take fractional quantities of items.
// Show the total value and what fractions you pick.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int id;
    float profit;
    float weight;
    float ratio;
};

bool cmp(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter the profit and weight of item no " << (i + 1) << ": ";
        cin >> items[i].profit >> items[i].weight;
        items[i].id = i + 1;
        items[i].ratio = items[i].profit / items[i].weight;
    }

    int capacity;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;

    sort(items.begin(), items.end(), cmp);

    float totalProfit = 0.0;
    vector<float> taken(n, 0.0);

    for (int i = 0; i < n && capacity > 0; ++i) {
        if (capacity >= items[i].weight) {
            taken[i] = 1.0;
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            taken[i] = (float)capacity / items[i].weight;
            totalProfit += taken[i] * items[i].profit;
            capacity = 0;
        }
    }

    cout << "\nItem No\tProfit\t\tWeight\t\tAmount to be taken\n";
    for (int i = 0; i < n; ++i) {
        cout << items[i].id << "\t" << items[i].profit << "\t\t" << items[i].weight << "\t\t" << taken[i] << endl;
    }
    cout << "Maximum profit: " << totalProfit << endl;

    return 0;
}

