class Solution {
public:
    bool check(int &m,vector<int> &piles,int &hour)
    {
        double count=0,i=0,val=0;
        while(i<piles.size())
        {
            count=piles[i++];
            // cout<<count<<" ";
            val+= ceil(count/m);
            // cout<<val<<endl;
        }
        
        return val<=hour;
    }
    int minEatingSpeed(vector<int>& piles, int hour) {
       // if(h==piles.size) max of piles
        double sum=0;
        int l=0,h=0,m=0;
        for(auto x:piles)sum+=x,h=max(h,x);
        l= ceil(sum/hour);
        while(l<=h)
        {
            m=(l+h)>>1;
            // cout<<l<<" "<<m<<" "<<h<<endl;
            if(check(m,piles,hour))//if eaten by whole then simly 
                h=m-1;
            else
                l=m+1;
        }
        return l;
    }
};