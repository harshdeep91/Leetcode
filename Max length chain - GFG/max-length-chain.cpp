// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
static bool cmp(val &A,val &B)
{
    return A.second<B.second||(A.second==B.second&&A.first<B.first);
}
int maxChainLen(struct val p[],int n)
{
       sort(p,p+n,cmp);
       int count=1,k=0;
       for(int i=1;i<n;i++)
       {
           if(p[i].first>p[k].second)
           {
               count++;
               k=i;
           }
          
       }
       return count;
    
}

