class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int a[256]={0},count=0,i=0,j=0;
        while(i<p.size())
        {
            a[p[i]]++;
            if(a[p[i]]==1)
                count++;
            i++;
        }
        i=0;
        vector<int> ans;
        while(j<s.size())
        {
            a[s[j]]--;
            if(a[s[j]]==0)
                count--;
            if(j-i+1==p.size())
            {
                if(count==0)
                    ans.push_back(i);
                if(a[s[i]]==0)
                    count++;
                a[s[i++]]++;
                
            }  
            j++;
        }
        return ans;
    }
};