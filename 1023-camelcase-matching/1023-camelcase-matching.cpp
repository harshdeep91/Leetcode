class Solution {
public:
    vector<bool> camelMatch(vector<string>& q, string p) {
        vector<bool> ans(q.size(),0);
        int j,k;
        //if capital letter matches pattern then it is the ans
        for(int i=0;i<q.size();i++)
        {
            j=0,k=0;
            while(k<p.size()&&j<q[i].size())
            {
                if(q[i][j]==p[k])
                    k++;
                else if(q[i][j]>='A'&&q[i][j]<='Z')j=q[i].size();
                j++;
                // cout<<k<<" "<<j<<endl;
            }
            
            if(k==p.size())//means we got the pattern
            {
                //we check if we have any j left that have no capital letter
                while(j<q[i].size()&&q[i][j]>='a'&&q[i][j]<='z')j++;
                ans[i]=(j==q[i].size());
            }
        }
        return ans;
    }
};