class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        //find maximum array of sum 0
        int i=0,j=0,sum=0,mx=0;
        while(j<seats.size())
        {
            sum+=seats[j++];
            if(sum==0)mx=max((i==0||j==seats.size())?2*(j-i):(j-i),mx);
            else
            {
                i=j;
                sum=0;
            }
        }
        return ceil(mx/2.0);
    }
};