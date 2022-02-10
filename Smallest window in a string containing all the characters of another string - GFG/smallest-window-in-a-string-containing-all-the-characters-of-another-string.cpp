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
        int i=0,j=0,pm[26]={0},count=0,st=0,e=s.size();
        while(i<p.size())
        {
            pm[p[i]-'a']++;
            if(pm[p[i]-'a']==1)
            count++;
            i++;
        }
        i=0;
        while(j<s.size())
        {
            pm[s[j]-'a']--;
            if(pm[s[j]-'a']==0)
            count--;
            while(count==0&&i<=j)
            {
                if(e-st>j-i)
                {
                    e=j;
                    st=i;
                }
                pm[s[i]-'a']++;
                if(pm[s[i]-'a']==1)
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