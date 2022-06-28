class Solution {
public:
    int numRabbits(vector<int>& a) {
        //new solving pattern
        //think in 5 min 
        // if not use 1st hint 5 min
        //  use second hint 5 min
        //solve for 5 min
        // if not stop see ans
        //only 20 min give
        sort(a.begin(),a.end());
        int count=0,i=0;
        while(i<a.size())
        {
           //said the 1 rabbit then we will check next value
                int j=1;//means next rabbits must be of same answer
                count+= a[i]+1;
                while(j<=a[i])
                {
                    if(i+j<a.size()&&a[i+j]==a[i])
                    {
                        j++;
                        // count++;
                    }
                    else break;
                }
              // cout<<i<<" "<<j<<" "<<count<<endl;
                i=i+j;
        }
        return count;   
    }
};