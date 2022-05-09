class Solution {
public:
    #define pii pair<int,int>
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>pq;
        pq.push({nums1[0]+nums2[0],{0,0}});
        vector<vector<int>>ans;
        while(!pq.empty() and k--)
        {
            int x=pq.top().first;
            int left=pq.top().second.first;
            int right=pq.top().second.second;
            ans.push_back({nums1[left],nums2[right]});
            pq.pop();
            if(right<nums2.size()-1 and left==0)
                pq.push({nums1[left]+nums2[right+1],{left,right+1}});
            if(left<nums1.size()-1)
                pq.push({nums1[left+1]+nums2[right],{left+1,right}});
            
        }
        return ans;
    }
};