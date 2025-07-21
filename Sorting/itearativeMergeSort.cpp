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
        if(L[i] > R[j])
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
void itMergeSort(int arr[], int n)
{
    int p;
    for( p = 2; p<=n; p = p*2)
    {
        for(int i=0; i+p -1 <  n ; i = i+p)
        {
            int l = i;
            int h = i+p -1;
            int mid = ( l+h )/2;
            Merge(arr, l, mid, h);
        }
    }
    int last = p/2;
    if(last <n )
    {
      int  mid = last -1;
        Merge(arr , 0, mid , n-1);
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
    itMergeSort(arr,n);
     for(int i=0; i<n; i++)
    {
        cout<< arr[i] <<" ";
    }
    cout <<endl;
    return 0;
}
