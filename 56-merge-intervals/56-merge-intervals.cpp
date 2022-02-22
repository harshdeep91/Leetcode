class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int i=1,j=0;
        vector<vector<int>> ans;
        ans.push_back({arr[0]});
        while(i<arr.size())
        {
            if(arr[i][0]<=ans[j][1])//()
            {
                if(arr[i][1]>ans[j][1])//partial inside
                {
                    ans[j][1]=arr[i][1];
                }
            }
            else //outside
            {
                ans.push_back(arr[i]);
                j++;
            }
            i++;
        }
        return ans;
    }
};