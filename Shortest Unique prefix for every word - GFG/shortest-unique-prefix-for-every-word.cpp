// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
struct trie{
    trie *child[26]={0};
    int wordcount=0;
};
class Solution
{
    public:
    void insert(trie *root,string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(!root->child[s[i]-'a'])
            root->child[s[i]-'a']=new trie;
            root=root->child[s[i]-'a'];
            root->wordcount++;
        }
    }
    string search(trie *root,string s)
    {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            root=root->child[s[i]-'a'];
            ans+=s[i];
            if(root->wordcount==1)
            break;
        }
        return ans;
    }
    vector<string> findPrefixes(string arr[], int n)
    {
       trie *root=new trie;
       for(int i=0;i<n;i++)
           insert(root,arr[i]);
           vector<string> v;
           for(int i=0;i<n;i++)
               v.push_back(search(root,arr[i]));
           return v;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends