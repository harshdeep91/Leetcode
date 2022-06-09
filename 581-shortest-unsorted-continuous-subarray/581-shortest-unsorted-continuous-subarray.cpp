class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 2 4 
        //check decreasing order if exist then find smallest index that is greater
        stack<int> s;
        int mi=nums.size(),mx=-1,prev,curr;
        for(int i=0;i<nums.size();i++)
        {
            curr=i;
            if(!s.empty()&&nums[s.top()]>nums[i])
                curr=s.top(),s.pop();
            prev=curr;
            while(!s.empty()&&nums[s.top()]>nums[i])
                prev=s.top(),s.pop();
            if(curr!=i&&nums[curr]>=nums[i])
            {
                mi=min(mi,prev);
                mx=max(mx,i);
                s.push(prev);
                if(prev!=curr)
                s.push(curr);
            }
            else
            s.push(i);
            // cout<<mi<<" "<<mx<<endl;
        }
            return mx==-1?0:mx-mi+1;
    }
};