class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> prev={1};
            v.push_back(prev);
        if(numRows==1)
            return v;
          prev.push_back(1);
            v.push_back(prev);
        if(numRows==2)
            return v;
        numRows--;
        while(--numRows)
        {
            vector<int> curr={1};
            for(int i=0;i<prev.size()-1;i++)
                curr.push_back(prev[i]+prev[i+1]);
                curr.push_back(1);
            prev=curr;
            v.push_back(prev);
        }
        return v;
    }
};