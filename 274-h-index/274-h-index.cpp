class Solution {
public:
    bool check(vector<int>& citations,int &i)
    {
        int notgreater=citations.size()-i;
        for(int j=0;j<citations.size();j++)
            {
                    if(citations[j]<i)
                    {
                        if(notgreater)
                            notgreater--;
                        else
                            return 0;
                    }
            }
        return 1;
    }
    int hIndex(vector<int>& citations) {
        int n=citations.size(),j,notgreater,l=0,h=n;
        while(l<=h)
        {
           
            int mid=(l+h)/2;
            if(check(citations,mid))
                l=mid+1;
            else
                h=mid-1;
             // cout<<i<<" "<<notgreater<<endl;
            
        }
        return h;
    }
};