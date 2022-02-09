// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    int ans0=0,ans1=0;
    for(int i=0;i<S.size();i++)
    {
        //ans0 odd place =1
        //ans1 odd place=0
        if((i&1&&S[i]!='1')||(!(i&1)&&S[i]!='0'))//odd means 0
        ans0++;
    }
    ans1=S.size()-ans0;
    // cout<<ans1<<" "<<ans0<<endl;
    return min(ans0,ans1);
    
}