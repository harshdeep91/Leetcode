class Solution {
    set<string> st;
    vector<vector<int>> ans;
    vector<int> num;
public:
    void solve(int i,vector<int> v,string s)
    {
        if(i==num.size())
        {
            if(st.find(s)==st.end()&&v.size()>1)//not exist
            {
                st.insert(s);
                ans.push_back(v);
            }
            return;
        }
         //include only when it is empty or element greater
        if(v.empty()||num[i]>=v.back())
        {
            v.push_back(num[i]);
            solve(i+1,v,s+"*"+to_string(num[i]));
            v.pop_back();
        }
            solve(i+1,v,s); //not include
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        num=nums;
        solve(0,{},"");
        return ans;
    }
};