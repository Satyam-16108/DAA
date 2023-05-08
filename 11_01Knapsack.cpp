#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> weights, vector<int> values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= capacity; j++) {
            if(weights[i - 1] <= j) {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][capacity];
}

int main() {
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int capacity = 50;
    int result = knapsack(weights, values, capacity);
    cout << "Maximum Value: " << result << endl;
    return 0;
}
