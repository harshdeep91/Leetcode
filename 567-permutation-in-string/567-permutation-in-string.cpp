class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //first check every permutation 
        // second approach we only need continuos count 
        if(s1.size()>s2.size())return 0;
        int j=0,i=0,k=0,a[26]={0};
        while(i<s1.size())
            a[s1[i++]-'a']++;
        while(j<s1.size()-1)
            a[s2[j++]-'a']--;
        i=0;
        while(j<s2.size())
        {
              a[s2[j++]-'a']--;
            for(k=0;k<26&&!a[k];k++);
            if(k==26) return 1;
             a[s2[i++]-'a']++;
        }
        return 0;
    }
};