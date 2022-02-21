// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    priority_queue<int,vector<int>,greater<int>> mi;
    priority_queue<int> ma;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(ma.empty())
        ma.push(x);
        else if(ma.size()>mi.size())
        {
            if(x<=ma.top())
            {
                mi.push(ma.top());
                ma.pop();
                ma.push(x);
            }
            else
                mi.push(x);
        }
        else//size equal
        {
            if(x<=mi.top())
            ma.push(x);
            else 
            {
                ma.push(mi.top());
                mi.pop();
                mi.push(x);
            }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(ma.size()>mi.size())
        return ma.top();
        else
        // cout<<mi.top()<<" "<<ma.top()<<endl;
         return  (double)(mi.top()+ma.top())/2;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Endsr