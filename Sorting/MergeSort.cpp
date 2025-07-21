#include<bits/stdc++.h>
using namespace std;
void Merge(int arr[], int l,int mid,int h)
{
    int nl = mid - l +1;
    int nr = h - mid;
    int L[nl],R[nr];
    for(int i=0; i<nl; i++)
    {
        L[i] = arr[ l +i ];
    }
    for(int i=0; i<nr; i++)
    {
        R[i] = arr[ mid +1 + i];
    }
    int i =0,j=0,k = l;
    while(i < nl && j < nr)
    {
        if(L[i] < R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while(i < nl)
    {
        arr[k++] = L[i++];
    }
    while(j < nr)
    {
        arr[k++] = R[j++];
    }
}
void MergeSort(int arr[] ,int l ,int h)
{
    if(l<h)
   {
    int mid = (l + h) /2;
   MergeSort(arr , l , mid);
   MergeSort(arr , mid+1 , h);
   Merge(arr , l, mid ,h);
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
    MergeSort(arr, 0 , n-1);
     for(int i=0; i<n; i++)
    {
        cout<< arr[i] <<" ";
    }
    cout <<endl;
    return 0;
}
