// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<int> aux(nums.begin(),nums.end());
	    sort(aux.begin(),aux.end());
	    unordered_map<int,int> m;
	    for(int i=0;i<nums.size();i++)
	       m[nums[i]]=i;
	    int count=0;
	    for(int i=0;i<nums.size();i++)
	    {
	        if(nums[i]!=aux[i])
	        {
	            count++;
	            int k=m[aux[i]];
	            swap(nums[i],nums[m[aux[i]]]);
	            m[nums[k]]=k;
	        }
	       // cout<<nums[i]<<" ";
	    }
	   // cout<<endl;
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends