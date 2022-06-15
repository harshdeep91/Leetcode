class Solution {
public:
    int check(string &s,string &t)
    {
        if(s.size()+1!=t.size())return 0;
        int i=0,j=0,add=0;
        while(i<s.size()&&j<t.size())
        {
            if(s[i]==t[j])i++,j++;
            else if(!add)j++,add=1;
            else return 0;
        }
        
        return (j<t.size()&&!add)||(i==s.size()&&j==t.size());
    }
    static bool cmp(string &s,string &t)
    {
        return s.size()<t.size()||(s.size()==t.size()&&s<t);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        // for(int i=0;i<words.size();i++)cout<<words[i]<<" ";
        // cout<<endl;
        vector<int> ans(words.size(),1);
        int mx=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(check(words[i],words[j]))
                    ans[j]=max(ans[j],ans[i]+1);
            }
            mx=max(ans[i],mx);
            // cout<<ans[i]<<" ";
        }
        // cout<<endl;
        return mx;
    }
};