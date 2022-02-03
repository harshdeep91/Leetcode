// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
      void solve(unordered_set<string> &m,string s,string ans,vector<string> &v){
          string j;
        //   cout<<s<<" "<<i<<n<<endl;
          if(!s.size())
          {
              ans.pop_back();
              v.push_back(ans);
              return;
          }
           for(int i=0;i<s.size();i++)
           {
               j+=s[i];
            //   cout<<" "<<i<<j<<" ";
               if(m.find(j)!=m.end())
               {
                //   cout<<"called "<<endl; 
                   solve(m,s.substr(i+1,s.size()-i+1),(ans+j+" "),v);
               }
           }
      }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        unordered_set<string> m;
        for(int i=0;i<n;i++)
        m.insert(dict[i]);
         vector<string> v;
   
         solve(m,s,"",v);
        
         return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends