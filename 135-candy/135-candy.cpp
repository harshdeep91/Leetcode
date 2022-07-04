class Solution {
public:
    int candy(vector<int>& r) {
        vector<int> candy(r.size(),1);
        int pr,nx,count=0;
        for(int i=0;i<r.size();i++)
        {
            candy[i]=i-1>=0&&r[i]>r[i-1]?candy[i-1]+1:1;
            // nx=i+1<r.size()&&r[i]>r[i+1]?candy[i+1]:0;
            // candy[i]=max(pr,nx)+1;
            cout<<candy[i]<<" ";
            // count+=candy[i];
        }
        cout<<endl;
        for(int i=r.size()-1;i>=0;i--)
        {
            candy[i]=i+1<r.size()&&r[i]>r[i+1]?max(candy[i],candy[i+1]+1):candy[i];
            
            count+=candy[i];
        }
        for(int i=0;i<r.size();i++)
            cout<<candy[i]<<" ";
        cout<<endl;
        return count;
    }
};