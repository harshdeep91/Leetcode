// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends


string solve(string &s)
{
    stack<char> st;
      for(int i=0;i<s.size();i++)
      {
               if(!st.empty()&&s[i]=='}'&&st.top()=='{')
               st.pop();
               else
               st.push(s[i]);
      }
      string ans;
      while(!st.empty())
      {
          ans+=st.top();
          st.pop();
      }
      reverse(ans.begin(),ans.end());
      return ans;
}
int countRev (string s)
{
     s=solve(s);
     if(s.size()&1)
     return -1;
     int ans=s.size()/2,count=0;
     stack<char> st;
    //   cout<<s<<endl;
     for(int i=0;i<s.size();i++)
     {
               if(!st.empty()&&s[i]=='}'&&st.top()=='{')
                    st.pop();
               else 
                {
                    if(s[i]=='}')
                        {
                            count++;
                           st.push('{');
                        }
                     else
                     {
                         if(i>=ans&&!st.empty()&&st.top()=='{')
                          {
                              count++;
                              st.pop();
                          }
                          else
                          {
                              st.push('{');
                          }
                           
                     }
                }
     }
    return count;
}