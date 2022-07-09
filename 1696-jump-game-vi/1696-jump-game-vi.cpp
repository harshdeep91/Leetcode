class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
       //use queue and sliding window
        // queue because we neeed max last value
        //brute force method could be start from i and j=i-1
        //check for every index
        
        deque<pair<int,int>> q; //q size must be k
        q.push_back({nums[0],0});
        int sum=0,front=0;
        for(int i=1;i<nums.size();i++)
        {
            sum=nums[i]+q.front().first;
            //now neutralise
            while(!q.empty()&&q.back().first<sum)
                q.pop_back();
            if(!q.empty()&&i-q.front().second>=k)
                q.pop_front();
            q.push_back({sum,i});
        }
        // while(!q.empty())
        //     cout<<q.front().first<<" "<<q.front().second<<endl,q.pop_front();
        return q.back().first;
    }
};