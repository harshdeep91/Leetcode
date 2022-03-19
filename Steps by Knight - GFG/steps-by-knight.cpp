// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    static bool check(int i,int j,vector<vector<int>> &mat)
    {
        if(i>=0&&i<mat.size()&&j>=0&&j<mat.size()&&mat[i][j]==0)
        {
            mat[i][j]=1;
            return true;
        }
        return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<int>> mat(N,vector<int>(N,0));
	    int x=N-TargetPos[1];
	    int y=TargetPos[0]-1;
	    queue<pair<int,int>> q;
	    q.push({N-KnightPos[1],KnightPos[0]-1});
	    int count=0;
	    int a[4]={-2,-1,1,2};
	    while(!q.empty())
	    {
	        int size=q.size();
	        while(size--)
	        {
	            int i=q.front().first;
	            int j=q.front().second;
	            q.pop();
	           // cout<<i<<" "<<j<<endl;
	            if(i==x&&j==y)
	            return count;
	            // 6position
	            for(int dx=0;dx<4;dx++)
	            {
	                for(int dy=0;dy<4;dy++)
	                {
	                   // cout<<i+a[dx]
	                    if((abs(a[dx]+a[dy])==3||abs(a[dx]+a[dy])==1)&&check(i+a[dx],j+a[dy],mat))
	                         q.push({i+a[dx],j+a[dy]});
	                }
	            }    
	        }
	        count++;
	       // cout<<endl<<count<<endl;
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends