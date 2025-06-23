#include<bits/stdc++.h>
using namespace std;
  int minCoins(int coins[] , int n, int amount)
  {
      sort(coins , coins + n ,greater<int>());
      int res =0;
      for(int i =0;i<n;i++)
      {
          if(coins[i] <= amount)
          {
              int c = amount /coins[i];
              res =res + c;
              amount = amount - c*coins[i];
          }
          if(amount == 0)
            break;
      }
      return res;
  }
int main()
{
    int n;
    cout <<"Enter number of Coins :"<<endl;
    cin >> n;
    int coins[n];
    for(int i =0;i<n;i++)
    {
        cin >> coins[i];
    }

    int amount;
    cout << "Enter Amount :"<<endl;
    cin >> amount;
    int res = minCoins(coins , n, amount);
    cout << "Minimum Number of Coins = "<<res<<endl;
    return 0;
}
