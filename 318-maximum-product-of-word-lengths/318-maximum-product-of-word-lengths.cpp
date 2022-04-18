class Solution {
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(),words.end());
        for(int i=0;i<words.size();i++)
            sort(words[i].begin(),words[i].end());
        int mx=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                int k=0, t=0;
                while(k<words[i].size()&&t<words[j].size())
                {
                    if(words[i][k]==words[j][t])
                        break;
                    else if(words[i][k]<words[j][t])
                        k++;
                    else
                        t++;
                }
                if(k==words[i].size()||t==words[j].size())
                {
                    t=words[i].size()*words[j].size();
                    mx=max(mx,t);
                }   
            }
        }
        return mx;
    }
};