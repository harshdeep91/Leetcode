class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sm=0;
        for(int i=1;i<strs.size();i++)
            if(strs[i].size()<strs[sm].size())
                sm=i;
        int i=0,j=0,k=strs[sm].size();
        while(i<strs.size())
        {
            j=0;
            while(j<k)
            {
                if(strs[i][j]!=strs[sm][j])
                    k=j;
                j++;
            }
            i++;
        }
        return strs[0].substr(0,k);
    }
};