// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        int a[256]={0};
        priority_queue<int>q;
        for(int i=0;i<s.size();i++)
        a[s[i]]++;
        for(auto x:a)
        if(x>0)
        q.push(x);
        while(k--)
        {
            int x=q.top();
            x--;
            q.pop();
            if(x)
            q.push(x);
        }
        int sum=0;
        while(!q.empty())
        {
            sum+=q.top()*q.top();
            q.pop();
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends