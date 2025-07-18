#include<bits/stdc++.h>
using namespace std;
void Warshall(vector<vector<int>>&a,int n)
{
    for(int k =0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(a[i][j] == 0)
                {
                    if(a[i][k] ==1 && a[k][j] == 1)
                    {
                        a[i][j] = 1;
                    }
                }
            }
        }
    }
    cout << "The Transitive Closure / Path matrix :\n";

}
int main()
{
    int n;
    cout <<"Enter Number of vertices : \n";
    cin >> n;
    vector<vector<int>>a(n,vector<int>(n));
    cout << "Enter the Adjacency Matrix :\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> a[i][j];
        }
    }
    Warshall(a, n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout <<  a[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}
