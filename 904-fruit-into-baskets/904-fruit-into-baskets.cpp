class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //brute force start from any index and check every time
        // here we only want max 2 consecutive elements in subarray
        // or largest size subarray with only two element
        //update the last index to avoid starting from prev
        int i=0,j=0,f=-1,s=-1,lf=-1,ls=-1,count=0,mx=0;
        while(j<fruits.size())
        {
           
            if(f==-1)//assign this fruit to f
                f=fruits[j],lf=j;
            else if(s==-1&&fruits[j]!=f)
                s=fruits[j],ls=j;
            
            if(fruits[j]==f)lf=j;//updating last index
            if(fruits[j]==s)ls=j;//updating last index
            if(s!=-1&&f!=-1)//means both fruits are assigned
            {
                if(f!=fruits[j]&&s!=fruits[j])//different value came
                {
                    //update last min index to i
                    if(lf<ls)//last fruits is first
                    {
                        i=++lf;
                        f=s;
                        lf=ls;
                        s=fruits[j];
                        
                        ls=j;
                    }
                    else
                    {
                        i=++ls;
                        s=fruits[j];
                        ls=j;
                    }
                }
            }
            j++;
            mx=max(j-i,mx);
             // cout<<fruits[j-1]<<" i= "<<i<<" j= "<<j-1<<" f= "<<f<<" s= "<<s<<" lf= "<<lf<<" ls= "<<ls<<" j-i= "<<j-i<<" mx= "<<mx<<endl;
        }
        return mx;
    }
};