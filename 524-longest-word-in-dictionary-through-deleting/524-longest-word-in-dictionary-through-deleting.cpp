class Solution {
public:
    static bool cmp(string &a,string &b)
    {
            return a.size()>b.size()||(a.size()==b.size()&&a<b);
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        // sort(dictionary.begin(),dictionary.end(),cmp);//n*k*log(n)
        string ans;
        for(auto x:dictionary)
        {
            int j=0,i=0;
            while(i<x.size()&&j<s.size())
                if(x[i]==s[j])i++,j++;
                else j++;
            if(i==x.size()&&(x.size()>ans.size()||(x.size()==ans.size()&&x<ans)))
                ans=x;
                
        }
        return ans;
    }
};