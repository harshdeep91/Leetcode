class Solution {
public:
    int minimumLines(vector<vector<int>>& sp) {
        
        int n = sp.size();
        sort(sp.begin(), sp.end());
        long double last_slope = LONG_MIN;
        int lines = 0;
        
        for(int i = 0; i < n-1; i++)
        {
            long double x = (sp[i+1][0] - sp[i][0]);
            long double y = (sp[i+1][1] - sp[i][1]);
            long double cur_slope = y / x;
            if(last_slope == cur_slope) continue;
            else {
                lines++;
                last_slope = cur_slope;
            }
        }
        
        return lines;
    }
};