class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        int n=nums1.size(),i=0,j=0,last=n-1;
        vector<int> ans(n,-1);
        vector<pair<int,int>> v;
        for(int i=0;i<nums2.size();i++)v.push_back({nums2[i],i});
        sort(nums1.begin(),nums1.end());
        sort(v.begin(),v.end());
        while(i<n&&j<n)
        {
            if(nums1[i]>v[j].first)
            {
                ans[v[j].second]=nums1[i];
                i++,j++;
            }
            else//put the value in last
            {
                ans[v[last--].second]=nums1[i++];
            }
        }
        return ans;
    }
};