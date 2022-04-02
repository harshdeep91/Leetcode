// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int search(string txt, string pat)
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
            i=0,j=-1;
            while(i<n)
            {
                
                if(j==pat.size()-1)
                  {
                    //   ans.push_back(i-pat.size()+1);
                    //   j=-1;
                    return true;
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
                    //   ans.push_back(i-pat.size()+1);
                    //   j=-1;
                    return true;
                  }
            // cout<<endl;
            return false;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string x, y;
   		cin >> x >> y;



        Solution ob;
   		cout << ob.search(x, y) << "\n";
   	}

    return 0;
}  // } Driver Code Ends