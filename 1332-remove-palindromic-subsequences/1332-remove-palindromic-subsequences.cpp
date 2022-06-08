class Solution {
public:
    int removePalindromeSub(string s) {
        int count=0,remain=0,counta=0,countb=0;
        int i=0,j=s.size()-1;
        while(i<j&&s[i]==s[j])i++,j--;
        if(i>=j)return 1;
        return 2;
    }
};