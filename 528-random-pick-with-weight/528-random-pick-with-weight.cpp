class Solution {
    vector<int> weight;
public:
    Solution(vector<int>& w) {
        weight.push_back(0);
        for(int i=0;i<w.size();i++)
            weight.push_back(weight[i]+w[i]);
        // for(auto x:weight)
        //     cout<<x<<" ";
        // cout<<endl;
    }
    
    int pickIndex() {
        int val = ((double)rand()/RAND_MAX)*weight.back();
        // cout<<val<<" ";
        int index=upper_bound(weight.begin(),weight.end(),val)-weight.begin();
        return index-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */