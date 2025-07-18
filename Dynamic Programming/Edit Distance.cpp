#include<bits/stdc++.h>
using namespace std;
int  ED(string s1,string s2,int n1,int n2)
{
    vector<vector<int >>dp(n2+1, vector<int >(n1+1));
    for(int i=0; i<= n2; i++)
    {
        dp[i][0] = i;
    }
    for(int i=0; i<= n1; i++)
    {
        dp[0][i] = i;
    }

    for(int i = 1; i <= n2; i ++)
    {
        for(int j =1; j <= n1; j ++)
        {
            if(s1[j-1] == s2[i-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1])) +1;
            }
        }
    }
    return dp[n2][n1];
}
int main()
{
    string s1, s2;
    cout << "Enter two Strings :\n";
    cin >> s1 >>s2;
    int n1,n2;
    n1 = s1.length();
    n2 = s2.length();
    int res = ED(s1,s2,n1,n2);
    cout << "The minimum number of operations  = "<<res<<endl;
    return 0;
}
