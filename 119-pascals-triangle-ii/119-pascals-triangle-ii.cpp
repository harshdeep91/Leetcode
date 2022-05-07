class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev={1};
        while(rowIndex--)
        {
            vector<int> curr={1};
            for(int i=0;i<prev.size()-1;i++)
                curr.push_back(prev[i]+prev[i+1]);
                curr.push_back(1);
            prev=curr;
        }
        return prev;
    }
};