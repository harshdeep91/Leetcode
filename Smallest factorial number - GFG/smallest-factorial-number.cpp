// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int findNum(int n)
        {
            int high=INT_MAX,low=1,m,i,count,ans;
            while(low<=high)
            {
                m=low+(high-low)/2;
                i=5;
                count=0;
                while(m/i!=0)
                {
                    count+=m/i;
                    i*=5;
                }
                if(count>=n)
                {
                    ans=m;
                    high=m-1;
                }
                else
                low=m+1;
            }
            return ans;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends