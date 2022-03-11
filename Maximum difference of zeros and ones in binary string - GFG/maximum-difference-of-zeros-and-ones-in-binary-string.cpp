// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int i=0,j=0,zero=0,one=0,diff=0,mx=-1;
	    while(j<S.size())
	    {
	       // cout<<i<<" "<<j<<" "<<one<<" "<<zero<<endl;
	        S[j++]=='1'?one++:zero++;
	        diff=zero-one;
	            while(i<j&&diff<=0)
	            {
	               S[i++]=='1'?one--:zero--;
	               diff=zero-one;
	            }
	            mx=zero&&diff>mx?diff:mx;
	    }
	    return mx;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends