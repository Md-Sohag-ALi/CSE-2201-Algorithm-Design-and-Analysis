#include<bits/stdc++.h>
using namespace std;
void FloyedWarshall(vector<vector<int>>&distance,int n)
{
    for(int k =0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                distance [i][j] = min(distance[i][j], distance[i][k] + distance[k][j] );
            }
        }
    }

}
int main()
{
    int n;
    cout <<"Enter Number of vertices : \n";
    cin >> n;
    vector<vector<int>>distance(n,vector<int>(n));
    cout << "Eeter Weighted Matrix :\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> distance[i][j];
        }
    }

    FloyedWarshall(distance, n);

    cout << "The All pair Shortest path cost matrix :\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            if(distance[i][j] == INT_MAX)
            {
                cout<< "INF " ;
            }
            else
            {
                cout <<  distance[i][j] <<" ";
            }
        cout<<endl;
    }
    return 0;
}
