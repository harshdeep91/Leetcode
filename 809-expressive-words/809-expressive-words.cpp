class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        //simply count one by one
        int ans=0;
         
        for(auto x:words)
        {
           int count1=0,i=0,j=0,count2=0;
            char c;
            while(i<s.size()&&j<x.size())
            {
                count1=0,count2=0,c=s[i];
                while(i<s.size()&&c==s[i]) 
                    count1++,i++;
                //now count the same char in x
                    while(j<x.size()&&c==x[j])
                        count2++,j++;
                // cout<<c<<" "<<i<<" "<<j<<" "<<count1<<" "<<count2<<endl;
                if(count1<count2||(count1!=count2&&count1<3))
                {
                    i=0;
                    break;
                }
            }
            ans+=(i==s.size()&&j==x.size());
        } 
        return ans;
    }
};