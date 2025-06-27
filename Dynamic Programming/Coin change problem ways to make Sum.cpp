#include<bits/stdc++.h>
using namespace std;
int countWays(int coins[], int n, int target)
{
    int dp[n+1][target+1];

    for(int i = 0; i <= n; i ++)
    {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= target; j++)
    {
        dp[0][j] = 0;
    }

    for(int i =1; i <= n; i ++)
    {
        for(int j = 1; j <= target ; j++)
        {
            if(coins[i-1] > j )
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }

    }
    return dp[n][target];
}

int main()
{
    int n,target;
    cout << "Enter Number of Coins : \n";
    cin >> n;
    int coins[n];
    for(int i =0; i<n; i++)
    {
        cin >> coins[i];
    }
    cout << "Enter Targeted Value :\n";
    cin >> target;
    int res = countWays(coins, n, target);
    cout << "Number of Ways to make "<< target <<" is = "<< res <<endl;
    return 0;
}
