// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string findSubString(string str)
    {
        // Your code goes here   
        int j=0,i=0,count=0,ans=0,s=0,e=str.size();
        unordered_map<char,int> a,p;
        for(auto x:str)
           {
               a[x]++;
               if(a[x]==1)
               ans++;
           }
        while(j<str.size())
        {
              p[str[j]]++;
             if(p[str[j]]==1)
             count++;
            //  cout<<i<<" "<<j<<" "<<count<<endl;
                 while(count==ans&&i<=j)
                 {
                     if(e-s>j-i)
                     {
                         e=j;
                         s=i;
                     }
                     p[str[i]]--;
                     if(p[str[i]]==0)
                     count--;
                     i++;
                 }
                 j++;
        }
        return str.substr(s,e-s+1);
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends