// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<int> NSL(long long arr[],int n)
    {
       stack<pair<long long,int>> st;
       vector<int>v ;
       
       for(int i=0; i<n; i++)
       {
           if(st.size()==0)
               v.push_back(-1);
           else if(st.size()>0 && st.top().first<arr[i])
              v.push_back(st.top().second);
           else if(st.size()>0 && st.top().first>=arr[i])
           {
               while(st.size()>0 && st.top().first>=arr[i])
               st.pop();
               if(st.size()==0)
                v.push_back(-1);
                else
                v.push_back(st.top().second);
           }
           st.push({arr[i],i});
       }
       return v;
    }
    
vector<int> NSR(long long arr[],int n)
    {
       stack<pair<long long,int>> st;
       vector<int>v ;
       
       for(int i=n-1; i>=0; i--)
       {
           if(st.size()==0)
               v.push_back(n);
           else if(st.size()>0 && st.top().first<arr[i])
              v.push_back(st.top().second);
           else if(st.size()>0 && st.top().first>=arr[i])
           {
               while(st.size()>0 && st.top().first>=arr[i])
               st.pop();
               if(st.size()==0)
                v.push_back(n);
                else
                v.push_back(st.top().second);
           }
           st.push({arr[i],i});
       }
       reverse(v.begin(),v.end());
       return v;
    }
    
    long long getMaxArea(long long arr[], int n)
    {
       vector<int> r= NSR(arr,n);
       vector<int> l= NSL(arr,n);
       
       vector<int> width;
       long long mx=INT_MIN;
       
       for(int i=0; i<n; i++)
           width.push_back(r[i]-l[i]-1);
       for(int i=0; i<n; i++)
           mx=max(mx,arr[i]*width[i]);
    
       return mx;
       
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends