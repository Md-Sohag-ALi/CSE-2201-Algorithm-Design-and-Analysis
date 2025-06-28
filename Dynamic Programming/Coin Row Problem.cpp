#include<bits/stdc++.h>
using namespace std;
int CoinRow(int coins[] , int n)
{
    int dp[n];
    if(n == 0)
       return 0;
    if(n == 1)
       return coins[0];
       dp[0] = coins[0];
       dp[1] = max(coins[0] ,coins[1]);
    for(int i = 2 ;i< n ;i++)
    {
        dp[i] = max(coins[i] +dp[i - 2] , dp[i-1]);
    }
    return dp[n -1];
}
int main()
{
    int n;
    cout << "Enter Number of coins: \n";
    cin >> n;
    int coins[n];
    for(int i=0;i<n;i++)
    {
        cin >> coins[i];
    }
    int res = CoinRow(coins , n);
    cout << res<<endl;
    return 0;
}
