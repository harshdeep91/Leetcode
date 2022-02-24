// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        long long sum=0,total=0;
        int i=-1,j=0;
    
        while(j<n)
        {
            total+=p[j].petrol-p[j].distance;
            sum+=p[j].petrol-p[j].distance;
            // cout<<j<<" "<<sum<<endl;
            if(sum<0)
            {
                i=-1;
                sum=0;
            }
            else if(i==-1)
            {
                // cout<<"run";
                i=j;
            }
            j++;
        }
        return total>=0?i:-1;
       //Your code here
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends