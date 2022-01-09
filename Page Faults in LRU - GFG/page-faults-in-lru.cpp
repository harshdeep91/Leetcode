// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>()> q;
        // unordered_map<int,int> m;
        int i=0,count=0,used=0,l=0,capacity[C],j;
        while(i<N)
        {
            used=N;
           for(j=0;j<l;j++)
               {
                   if(pages[i]==pages[capacity[j]])
                   {
                       capacity[j]=i;
                       break;
                   }
                   if(used==N||capacity[used]>capacity[j])
                   used=j;
               }
           if(j==l)//page fault
           {
               if(l<C)
               capacity[l++]=i;
               else //remove least used put new
                   capacity[used]=i;
                   count++;
           }
            i++;
        }
        return count;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends