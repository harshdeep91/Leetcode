// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        string ans;
        S--;
        while(D--)
        {
            if(S==0)
            ans.push_back('0');
            else if(S<9)
            {
                  ans.push_back((S+'0'));
                  S=0;
            }
            else
            {
                ans.push_back('9');
                S-=9;
            }
        }
         reverse(ans.begin(),ans.end());
        if(ans[0]=='9')
        return "-1";
        ans[0]+=1;
       
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends