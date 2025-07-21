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
void QuickSort(int arr[], int l,int h)
{
    if(l < h)
    {
        int pidx = Partition(arr, l,h);
        QuickSort(arr, l,pidx-1);
        QuickSort(arr, pidx+1, h);
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
    QuickSort(arr, 0, n-1);
    for(int i=0; i<n; i++)
    {
        cout<< arr[i] <<" ";
    }
    cout <<endl;
    return 0;
}
