#include<bits/stdc++.h>
using namespace std;
double Ratio[100];
void Knapsack(int n , double profits[] ,double weights[] , int capacity)
{
    for(int i =0 ;i<n-1;i ++)
    {
        int max = i;
        for(int j = i +1 ;j < n;j++)
        {
            if( (profits[j] / weights[j])  > (profits[max] / weights[max]) )
            {
                max = j;
            }
        }
        swap(profits[i] ,profits[max]);
        swap(weights[i] , weights[max]);
    }
    int W = capacity;
    int i;
    for( i =0;i < n;i ++)
    {
        if(weights[i] <=  W)
        {
            Ratio[i] = 1;
            W -=weights[i];
        }
        else break;
    }
    if(i <= n)
    {
        Ratio[i] = W / weights[i];
    }
}

double profit_calculation(int n , double Ratio[] , double profits[] , int capacity)
{
  double max_profit = 0;
  for(int i =0;i<n;i++)
  {
      max_profit += Ratio[i] * profits[i];
  }

  return max_profit;
}
int main()
 {
     int n;
    cout << "Enter Number of Items :"<<endl;
    cin >> n;
    double profits[n];
    cout << "Enter profits for per item : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin >> profits[i];
    }
     double weights[n];
    cout << "Enter weights for per item : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin >> weights[i];
    }
    double capacity;
    cout << "Enter Knapsack Capacity :"<<endl;
    cin >> capacity;
    Knapsack( n ,profits , weights,capacity);
       double max_profit =  profit_calculation(n , Ratio , profits,capacity);
    cout << "MaxiMum profit :" << max_profit<<endl;
    return 0;
}
