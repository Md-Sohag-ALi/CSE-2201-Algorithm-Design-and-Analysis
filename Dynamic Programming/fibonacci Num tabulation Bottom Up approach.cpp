#include<bits/stdc++.h>
using namespace std ;
int fibo(int n)
{
    int table[n];
    table[0] = 0;
    table[1] = 1;
    for(int i = 2;i <=n;i++)
    {
        table[i] = table[i-1] +table[i-2];
    }
    return table[n];
}
int main()
{
    int n;
    cin >>n;
    int nthNum = fibo(n);
    cout << nthNum<<endl;
    return 0;
}
