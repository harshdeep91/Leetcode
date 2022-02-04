// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void solve(int i,string s,set<string> &m)
	{
	    if(i==s.size())
	    {
	        m.insert(s);
	        return;
	    }
	    for(int j=i;j<s.size();j++)
	    {
	        swap(s[i],s[j]);
	        solve(i+1,s,m);
	        swap(s[i],s[j]);
	    }
	}
		vector<string>find_permutation(string S)
		{
		    set<string> m;
		    solve(0,S,m);
		    vector<string> v;
		    for(auto x:m)
		    {
		        v.push_back(x);
		        m.erase(m.begin());
		    }
		    return v;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends