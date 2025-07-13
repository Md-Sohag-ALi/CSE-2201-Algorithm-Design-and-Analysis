#include<bits/stdc++.h>
using namespace std;
int LCS(string s1,string s2)
{
    int n = s1.size();
    int m = s2.size() ;
    vector<vector<int>>dp(n+1 , vector<int>(m+1));
    for(int i =0;i<=n;i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=m;j++)
        {
             if(s1[i-1] ==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string s1,s2;
    cout << "Enter two String S1 and S1 :\n";
    cin >> s1 >> s2;
    int res = LCS(s1,s2);
    cout <<"The LCS of the Given two Strings = "<< res << endl;
    return 0;
}
