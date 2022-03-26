// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
struct trie{
    trie *child[26]={0};
    int wordcount=0;
};
class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    void insert(trie *root,string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(!root->child[s[i]-'a'])
            root->child[s[i]-'a']=new trie;
            root=root->child[s[i]-'a'];
        }
        root->wordcount++;
    }
    bool search(trie *root,string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(root->child[s[i]-'a'])
            root=root->child[s[i]-'a'];
            else
            return false;
        }
        return root->wordcount;
    }
    bool solve(string s,trie *root)
    {
        if(s.size()==0)
        return true;
        for(int i=0;i<s.size();i++)
        {
            string l=s.substr(0,i+1);
            string r=s.substr(i+1,s.size()-i-1);
            // cout<<l<<" "<<r<<endl;
            if(search(root,l)&&solve(r,root))
            return true;
        }
        return false;
    }
    int wordBreak(string A, vector<string> &arr) {
       int n=arr.size();
       trie *root=new trie;
       for(int i=0;i<n;i++)
           insert(root,arr[i]);
          return solve(A,root);
           
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