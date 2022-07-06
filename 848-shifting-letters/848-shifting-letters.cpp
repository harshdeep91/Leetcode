class Solution {
public:
    string shiftingLetters(string s, vector<int>& sh) {
        
        for(int i=sh.size()-2;i>=0;i--)
            sh[i]=((long long)sh[i]+sh[i+1])%26;
        for(int i=0;i<s.size();i++)
        {
             // int val=            
            s[i]= ((s[i]-'a'+sh[i])%('z'-'a'+1))+'a';
        }
        return s;
    }
};