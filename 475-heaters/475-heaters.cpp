class Solution {
public:
    bool solve(int &m,vector<int>& houses, vector<int>& heaters) {
        int i=0,j=0;
        //left to right
        while(i<houses.size()&&j<heaters.size())
        {
            if(heaters[j]-m<=houses[i]&&houses[i]<=heaters[j]+m)
                i++;
            else
                j++;
        }
        if(i==houses.size())return 1;
        return 0;
    };
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end()),sort(heaters.begin(),heaters.end());
        int l=0,h=max(abs(heaters.back()-houses.front()),abs(heaters.front()-houses.back())),m;
        while(l<=h)
        {
            // cout<<l<<" "<<h<<endl;
            m=l+(h-l)/2;
            if(solve(m,houses,heaters))
                h=m-1;
            else
                l=m+1;
        }
        return l;
    }
};