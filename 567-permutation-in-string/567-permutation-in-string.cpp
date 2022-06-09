class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //first check every permutation 
        // second approach we only need continuos count 
        if(s1.size()>s2.size())return 0;
        int a[26]={0};
        for(int i=0;i<s1.size();i++)
            a[s1[i]-'a']++;
        int j=0,i=0,k=0;
        
        while(j<s1.size()-1)
        {
            a[s2[j++]-'a']--;
        }
        
        while(j<s2.size())
        {
               a[s2[j++]-'a']--;
                k=0;
            while(k<26&&!a[k])k++;
            if(k==26)return 1;
             a[s2[i++]-'a']++;
        }
        return 0;
    }
};