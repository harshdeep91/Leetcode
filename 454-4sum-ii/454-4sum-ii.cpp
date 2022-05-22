class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> f,s;
        for(int i=0;i<nums1.size();i++)
            for(int j=0;j<nums2.size();j++)
                f[nums1[i]+nums2[j]]++;
        for(int i=0;i<nums3.size();i++)
            for(int j=0;j<nums4.size();j++)
                s[nums3[i]+nums4[j]]++;
        int count=0;
        for(auto x:f)
                count+=s[-x.first]*x.second;
        return count;
            
    }
};