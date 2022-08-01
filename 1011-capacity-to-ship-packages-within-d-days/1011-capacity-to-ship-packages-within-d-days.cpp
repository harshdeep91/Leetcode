class Solution {
public:
    int check(long long int &capacity,vector<int>& w)
    {
        long long int sum=0,count=0;
        for(int i=0;i<w.size();i++)
        {
            sum+=w[i];
            if(w[i]>capacity)return INT_MAX;
            if(sum>capacity)
            {
                count++;
                sum=w[i];
            }
        }
        return count+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //minimum weight could be 1 and max is sum
        //we will binary search add the sum
        //count the partition if satisfies simply lower the h value
        long long int l=1,h=0,sum=0,m,count;
        for(int i=0;i<weights.size();i++)h+= weights[i];
        //
        while(l<=h)
        {
            m=(l+h)>>1;
            count= check(m,weights);
            // cout<<l<<" "<<m<<" "<<h<<" "<<count<<endl;
            if(count<=days)h=m-1;
            else l=m+1;
        }
        return l;
    }
};