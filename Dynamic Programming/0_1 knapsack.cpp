#include<bits/stdc++.h>
using namespace std;
void whichIncludeWhichNot(vector<vector<int>> &dp,int n, int M,int wt[])
{
    int  i = n, j = M;
    while(i>0 && j>0)
    {
        if(dp[i][j] == dp[i-1][j])
        {
            cout << i <<" 0"<<endl;
            i--;
        }
        else
        {
            cout << i << " 1"<<endl;
            j = j-wt[i-1];
            i--;
        }
    }
}
int Knapsack(int wt[], int p[],int n,int M)
{
    vector<vector<int>> dp(n+1,vector<int>(M+1));
    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 0;
    }
    for(int j=0; j<=M; j++)
    {
        dp[0][j] = 0;
    }

    for(int i =1 ; i <= n; i++)
    {
        for(int w=1; w <= M; w++)
        {
            if(w  >= wt[i-1] )
                dp[i][w] = max( p[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    whichIncludeWhichNot(dp,n,M,wt);
    cout<<endl;
    return dp[n][M];
}
int main()
{
    int n;
    cout << "Enter Number of Items :\n";
    cin >> n;
    int wt[n];
    int p[n];
    cout << "Enter Weight of per Items :\n";
    for(int i = 0; i < n; i ++)
    {
        cin >> wt[i];
    }
    cout << "Enter Profit of per Items :\n";
    for(int i = 0; i < n; i ++)
    {
        cin >> p[i];
    }
    int M;
    cout << "Enter Knapsack Capacity:\n";
    cin >> M;
    int res = Knapsack(wt,p,n,M);
    cout << res <<endl;
    return 0;
}
