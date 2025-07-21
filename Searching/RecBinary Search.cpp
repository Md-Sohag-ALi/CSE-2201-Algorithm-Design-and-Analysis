#include<bits/stdc++.h>
using namespace std;
int recBinarySearch(int arr[] ,int low ,int h ,int key)
{
    if( low ==  h)
    {
        if( arr[low] == key)
        {
            return low;
        }
        else
            return 0;
    }

    else{
        int mid = (low + h) /2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid]  > key)
            return recBinarySearch(arr , low ,mid-1,key);
        else if(arr[mid] < key)
            return recBinarySearch(arr , mid+1,h,key);
    }
    return 0;
}

int main()
{
    int n;
    cout <<"Enter Number of Element \n";cin >>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int k;cout<<"Enter Element to Search :\n";cin >>k;
    int res = recBinarySearch(arr,0,n,k);
    cout  << res <<endl;
    return 0;
}
