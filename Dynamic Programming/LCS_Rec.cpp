#include<bits/stdc++.h>
using namespace std;
int LCS_Rec(string s1 ,string s2,int n ,int m)
{
    if(s1[n] == '\0' || s2 [m] == '\0') return 0;
    else if(s1[n] == s2[m])
        return 1 +LCS_Rec(s1 ,s2,n-1, m-1);
    else
    return max(LCS_Rec( s1 ,s2 , n-1 ,m) ,LCS_Rec(s1,s2,n,m-1));
}
int main()
{
    string s1,s2;
    cin >>s1>>s2;
    int res = LCS_Rec(s1,s2 ,s1.size() -1 , s2.size()-1); //  s1.size() -1 , s2.size()-1 for out of bounds prevent
    cout << res <<endl;
}
