struct node{
    int sum,first, second;
};
class cmp{
  public:
    bool operator()(node A,node B){
        return A.sum <= B.sum;
    }
};
class Solution {
public:
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<node,vector<node>,cmp> p;
        int i = 0, j = 0;
        while(i<nums1.size())
        {
            j = 0;
            while(j<nums2.size())
            {
                // cout << nums1[i] << " " << nums2[j] << endl;
                if(p.size()<k)
                    p.push({nums1[i] + nums2[j], nums1[i], nums2[j]});
                else
                {
                    if(p.top().sum>nums1[i]+nums2[j])
                    {
                        p.pop();
                        p.push({nums1[i] + nums2[j], nums1[i], nums2[j]});
                    }
                    else
                        break;
                }
                    j++;
            }
            i++;
        }
        vector<vector<int>> v;
        while(!p.empty())
            {
                v.push_back({p.top().first, p.top().second});
                p.pop();
            }
                return v;
    }
};