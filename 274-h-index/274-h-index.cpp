class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(),citations.end());
        int n=citations.size(),j,notgreater,h=n;
        // for(int i=n-1;i>=0;i--)
        // {
        //     if(citations[i]<=n)
        //     {
        //         h=citations[i];
        //         break;
        //     }
        // }
        
        for(int i=h;i>=0;i--)
        {
           
            notgreater=n-i;
             // cout<<i<<" "<<notgreater<<endl;
            for(j=0;j<n;j++)
            {
                // if(i==3)
                //     cout<<citations[j]<<" "<<notgreater<<endl;
                if(notgreater)
                {
                    if(citations[j]>i)
                        break;
                    notgreater--;
                }    
                else if(citations[j]<i)
                    break;
            }
            if(j==n)
                return i;
        }
        return 0;
    }
};