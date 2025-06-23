#include<bits/stdc++.h>
using namespace std;
int flug = 0;
int Mfibonacci(int memo[], int n)
{
    if(memo[n] == -1)
    {
        if(n<0)
        {
            cout << "Error!"<<endl;
        }
        if(n == 0 || n == 1 )
        {
            memo[n] = n;
        }
        else
        {
            memo[n] = Mfibonacci(memo,n-1) + Mfibonacci(memo, n-2);
        }
    }
   return memo[n];
}

int fibonacci(int n)
{
    int memo[n+1];
    for(int i=0; i <= n; i++)
    {
        memo[i] = -1;
    }
    return Mfibonacci(memo, n);
}
int main()
{
    int n;
    cin >> n;

    int res = fibonacci(n);
    cout << res<<endl;
    return 0;
}
