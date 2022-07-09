class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int i=0,j=p.size()-1,count=0;
        while(i<j)
        {
            if(p[i]+p[j]<=limit)
                i++;
            // else if(p[i]+p[j]>limit)
                j--;
            count++;
        }
        count+= i==j;
        return count;
    }
    
};