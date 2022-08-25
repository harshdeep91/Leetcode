class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26]={0};
        for(int i=0;i<magazine.size();i++)a[magazine[i]-'a']++;
        for(int i=0;i<ransomNote.size();i++)
            if(a[ransomNote[i]-'a'])
                a[ransomNote[i]-'a']--;
        else return 0;
        return 1;
    }
};