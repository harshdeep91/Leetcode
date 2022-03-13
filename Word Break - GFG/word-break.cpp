// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
        unordered_set<string> s;
        bool solve(string A,vector<string> &B)
        {
            // cout<<A.size()<<endl;
            if(A.size()==0)
            {
                return 1;
            }
            string l,r;
            int i=0;
            while(i<A.size())
            {
                i++;
                l=A.substr(0,i);
                r=A.substr(i,A.size()-i);
                // cout<<l<<" "<<r<<endl;
                if(s.find(l)!=s.end()&&solve(r,B))
                return 1;
            }
            return 0;
        }
    int wordBreak(string A, vector<string> &B) {
        //code here]
        s.clear();
        for(auto x:B)
        s.insert(x);
        // for(auto b:s)
        // cout<<b<<" ";
        return solve(A,B);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends