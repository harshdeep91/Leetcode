class Solution {
public:
    void print(vector<int> &a)
    {
        for(auto x:a)cout<<x<<" ";
        cout<<endl;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        //we can do this by brute force by taking every possilbe
        //firstlen then secondlen 
        //or we can do other way by assigning small len first
        //after then we can find max len
        //we can find max subbarray with len1 and len2 
        //we can do max possible subarray from left,and from right
        if(f>s)swap(f,s);
        int n=nums.size(),i=0,j=0,fsum=0,ssum=0,mx=0,k=0;
        vector<int> lf(n,0),rf(n,0),ls(n,0),rs(n,0);
        //from left store len s and f
        cout<<f<<" "<<s<<endl;
        while(j<n)
        {
            fsum+= nums[j];
            ssum+= nums[j];
            if(j-i+1==f)
            {
                lf[j]=j==0?nums[j]:max(lf[j-1],fsum);
                fsum-=nums[i++];
            }
             if(j-k+1==s)
            {
                ls[j]=j==0?nums[j]:max(ls[j-1],ssum);
                ssum-=nums[k++];
            }
            j++;
        }
        //right to left
        j=n-1,i=n-1,k=n-1,fsum=0,ssum=0;
         while(j>=0)
        {
            fsum+= nums[j];
            ssum+= nums[j];
            if(i-j+1==f)
            {
                rf[j]=j==n-1?nums[j]:max(rf[j+1],fsum);
                fsum-=nums[i--];
            }
            if(k-j+1==s)
            {
                rs[j]=j==n-1?nums[j]:max(rs[j+1],ssum);
                ssum-=nums[k--];
            }
            j--;
        }
        // print(lf),print(ls),print(rf),print(rs);
        //now find max from lf and rs or ls or rs
        i=0;
        while(i<n-1)
        {
            mx=max(lf[i]+rs[i+1],max(mx,ls[i]+rf[i+1]));
            i++;
        }
        return mx;
        
    }
};