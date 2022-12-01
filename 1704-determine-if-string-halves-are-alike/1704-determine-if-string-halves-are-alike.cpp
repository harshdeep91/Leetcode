class Solution {
public:
    bool halvesAreAlike(string s) {
        int count=0;
        char c[10]={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i=0;i<s.size();i++)
            for(char x:c)
                if(s[i]==x)
            count+=i<s.size()/2?1:-1;
        return !count;
    }
};