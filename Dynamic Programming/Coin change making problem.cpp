#include <bits/stdc++.h>
using namespace std;

int CountMinCoins(int coins[], int n, int target) {
    int dp[n + 1][target + 1];

    // Base case
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 1; j <= target; j++) dp[0][j] = INT_MAX - 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i ][j - coins[i - 1]]);
        }
    }
         if (dp[n][target] == INT_MAX - 1)
        return -1; // Not possible
    return dp[n][target];
    }




int main() {
    int n;
    cout << "Enter Number of Coins:\n";
    cin >> n;
    int coins[n];
    cout << "Enter Coin Values:\n";
    for (int i = 0; i < n; i++) cin >> coins[i];
    int target;
    cout << "Enter Target Value:\n";
    cin >> target;

    int res = CountMinCoins(coins, n, target);
    if (res == -1)
        cout << "It's not possible to make " << target << " with the given coins.\n";
    else
        cout << "The Number of Minimum Coins To make " << target << " = " << res << endl;
    return 0;
}
