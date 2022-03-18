class Solution {
public:
    static bool cmp(vector<int> &A,vector<int> &B)
    {
        return A[1]<B[1]||A[1]==B[1]&&A[0]<=B[0];
    }
    int search(vector<vector<int>>& pairs,int i)
    {
        int l=0,h=i-1,m;
        while(l<=h)
        {
            m=(l+h)/2;
            if(pairs[m][1]>=pairs[i][0])
                h=m-1;
            else
                l=m+1;
        }
        // cout<<h<<endl; 
        if(h!=-1&&pairs[h][1]<pairs[i][0])
            return h;
            return -1;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        vector<int> dp(pairs.size(),1);
        for(int i=1;i<pairs.size();i++)
        {
            int index=search(pairs,i);
            if(index!=-1)
                dp[i]+=dp[index];
            dp[i]=max(dp[i-1],dp[i]);
            // cout<<pairs[i][0]<<" "<<pairs[i][1]<<" "<<index<<" "<<dp[i]<<endl;
        }
        return dp[pairs.size()-1];
    }
};