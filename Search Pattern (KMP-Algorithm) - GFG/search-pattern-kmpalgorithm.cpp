// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int n=txt.size(),i=0,j=0;
            vector<int> v(n,-1),ans;
            while(++j<n)
            {

                if(txt[i]==txt[j])
                    v[j]=i++;
                    else
                    i=0;
                    // cout<<v[j]<<" ";
            }
            bool flag=false;
            if(v[n-1]==n-1)
             flag=true;
             
            i=0,j=-1;
            while(i<n)
            {
                
                if(j==pat.size()-1)
                  {
                      ans.push_back(i-pat.size()+1);
                      j=v[j];
                      
                  }
                if(txt[i]==pat[j+1])
                {
                    i++;
                    j++;
                }
                else if(j==-1)
                i++;
                else
                j=v[j];
                // cout<<i<<" "<<j<<endl;
            }
            if(j==pat.size()-1)
                  {
                      ans.push_back(i-pat.size()+1);
                       j=v[j];
                  }
            // cout<<endl;
            return ans;
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends