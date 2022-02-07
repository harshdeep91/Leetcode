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


int countRev (string s)
{
     int temp=0, res=0, n=s.size();
   if(n%2!=0)
           return -1;
   for(int i=0;i<n;i++){
       if(s[i]=='{')
           temp++;
       else{
            if(temp==0){
                res++;
                temp++;
           }
           else
               temp--;
       }
   }
   if(temp>0)
       res += temp/2;
   return res;
}