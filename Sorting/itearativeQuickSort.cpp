#include<bits/stdc++.h>
using namespace std;
int Partition(int arr[],int l,int h)
{
    int i =l-1 ,j = h +1;
     int pivot = arr[l];
    while(i < j)
    {

        do
        {
            i ++;
        }
        while((i <= h ) && (arr[i] <= pivot));

        do
        {
            j --;
        }
        while((j >= l) && (arr[j] > pivot));
        if(i < j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[l] ,arr[j]);
    return j;
}
void itearativeQuickSort(int arr[] ,int l , int h)
{
    stack<pair<int , int >>st;
    st.push({l,h});
    while(!st.empty())
    {
        auto [l , h] = st.top() ;st.pop();
        if(l <h)
        {
            int pidx =  Partition(arr,l ,h);
            st.push({l , pidx});
            st.push({pidx+1 , h});
        }
    }
}
int main()
{
     int n;
    cout<<"Enter Number of Element :\n";
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    itearativeQuickSort(arr, 0, n-1);
    for(int i=0; i<n; i++)
    {
        cout<< arr[i] <<" ";
    }
    cout <<endl;
    return 0;
}
