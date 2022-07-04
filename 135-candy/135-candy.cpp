class Solution {
public:
    int candy(vector<int>& r) {
        vector<int> candy(r.size(),1);
        int pr,nx,count=0;
        for(int i=0;i<r.size();i++)
            candy[i]=i-1>=0&&r[i]>r[i-1]?candy[i-1]+1:1;
        for(int i=r.size()-1;i>=0;i--)
        {
            candy[i]=i+1<r.size()&&r[i]>r[i+1]?max(candy[i],candy[i+1]+1):candy[i];
            count+=candy[i];
        }
        return count;
    }
};