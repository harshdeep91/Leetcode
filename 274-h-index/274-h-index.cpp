class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size(),j,notgreater,h=n;
        for(int i=h;i>=0;i--)
        {
           
            notgreater=n-i;
             // cout<<i<<" "<<notgreater<<endl;
            for(j=0;j<n;j++)
            {
                // if(i==3)
                //     cout<<citations[j]<<" "<<notgreater<<endl;
                    if(citations[j]<i)
                    {
                        if(notgreater)
                            notgreater--;
                        else
                            break;
                    }
            }
            if(j==n)
                return i;
        }
        return 0;
    }
};