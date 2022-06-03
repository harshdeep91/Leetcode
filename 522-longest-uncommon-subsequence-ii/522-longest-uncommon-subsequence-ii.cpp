
class Solution {
    public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int maxLen = -1;
        for(int i = 0; i < strs.size(); i++){
            bool flag = false ;
            int currLen = strs[i].size();
            for(int j = 0 ; j<strs.size(); j++)
            {

                if(i != j && isSubsequence(strs[i], strs[j]))
                {
                    flag = true ;
                    break ;
                }
            }
            if(!flag)
            {
                maxLen = max(maxLen , currLen);
            }
        }
        return maxLen;
    }

     bool isSubsequence(string a, string b) {
        if (a==b) return true;
        int i = 0;
        int j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }

        return i == a.size();
    }
};