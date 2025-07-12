#include<bits/stdc++.h>
using namespace std;

int coinsCollectbyRobot(int n, int m ,vector<vector<int>>&coins)
{
  vector <vector<int>>dp(n+1 , vector<int>(m+1 ,0));

  for(int i=1;i<=n;i++)
  {
      for(int j = 1;j<=m ;j++)
      {
          dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]) +coins[i-1][j-1];
      }
  }
  return dp[n][m];

}
int main()
{
    int n,m;
    cout << "Enter the grid size :\n";
    cin >> n >> m;
  vector<vector<int>>coins(n , vector <int> (m));
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> coins[i][j];
        }
    }
    int res = coinsCollectbyRobot(n,m,coins);
    cout << res <<endl;
    return 0;
}
