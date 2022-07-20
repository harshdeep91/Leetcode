class Solution {
public:
    string ans="";
    void backtrack(vector<int>&arr,int pos,string curr,int mask)
    {
        int n=arr.size();
        if(pos==n)
        {
            if(curr[0]>='3')
                return;
            if(curr[0]=='2' && curr[1]>='4')
                return;
            if(curr[3]>='6')
                return;
            if(ans=="")
                ans=curr;
            else ans=max(ans,curr);
            return;
        }
        for(int i=0;i<4;i++)
        {
            if(mask & (1<<i))
                continue;
            char c='0'+arr[i];
            if(pos==2)
            backtrack(arr,pos+1,curr+":"+c,mask | (1<<i));
            else
            backtrack(arr,pos+1,curr+c,mask | (1<<i));
        }
    }
    string largestTimeFromDigits(vector<int>& arr) {
        string curr="";
        backtrack(arr,0,curr,0);
        return ans;
    }
};