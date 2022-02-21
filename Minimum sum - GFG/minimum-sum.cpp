// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        priority_queue<int> q;
        for(int i=0;i<n;i++)
        q.push(arr[i]);
        string ans;
        int carry=0,x,y,sum;
        while(q.size()>1)
        {
            x=q.top();
            q.pop();
            y=q.top();
            q.pop();
            sum=x+y+carry;
                carry=sum/10;
                 if(sum)
                ans.push_back((sum%10+'0'));
        }
        sum=carry;
        if(!q.empty())
        sum+=q.top();
      
            while(sum)
            {
                carry=sum;
                carry%=10;
                sum/=10;
                ans.push_back(carry+'0');
            }
            
            reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends