// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int i=0,j=0,pm[256]={0},count=0,st=0,e=s.size();
        while(i<p.size())
        {
            pm[p[i]]++;
            if(pm[p[i]]==1)
            count++;
            i++;
        }
        i=0;
        while(j<s.size())
        {
            pm[s[j]]--;
            if(pm[s[j]]==0)
            count--;
            while(count==0&&i<=j)
            {
                if(e-st>j-i)
                {
                    e=j;
                    st=i;
                }
                pm[s[i]]++;
                if(pm[s[i]]==1)
                count++;
                i++;
            }
            j++;
        }
        return e<s.size()?s.substr(st,e-st+1):"-1";
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends