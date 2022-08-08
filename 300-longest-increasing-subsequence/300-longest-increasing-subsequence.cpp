class Solution { 
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } 
            else {
                auto it = lower_bound(sub.begin(), sub.end(), x); 
                cout<<x<<" "<<*it<<endl;
                *it = x; 
                
            }
        }
        return sub.size();
    }
};