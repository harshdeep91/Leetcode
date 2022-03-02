// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int> > v;
        sort(arr.begin(),arr.end());
        int f=0,s,i,j;
        while(f<arr.size()-3)
        {
            // cout<<arr[f]<<" ";
            if(f==0||(f>0&&arr[f-1]!=arr[f]))
            {
                s=f+1;
                while(s<arr.size()-2)
                {
                    if(s==f+1||arr[s-1]!=arr[s])
                    {
                        i=s+1;
                        j=arr.size()-1;
                        while(i<j)
                        {
                            int x=arr[i]+arr[j]+arr[f]+arr[s];
                            if(x==k)
                            {
                                if(i==s+1||j==arr.size()-1||(i>s+1&&j<arr.size()-1&&arr[i-1]!=arr[i]&&arr[j+1]!=arr[j]))
                                v.push_back({arr[f],arr[s],arr[i],arr[j]});
                                i++;
                                j--;
                            }
                            else if(x>k)
                            j--;
                            else
                            i++;
                        }
                    }
                    s++;
                }
            }
            f++;
        }
        // cout<<arr[f]<<" "<<arr[f+1]<<" "<<arr[f+2]<<endl;
        // cout<<endl;
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends