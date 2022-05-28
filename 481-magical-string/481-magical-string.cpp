class Solution {
public:
    int magicalString(int n) {
        if(n<=2)return 1;
        int i=1,j=1,count=0;
        vector<int> arr(n+2);
        arr[0]=1,arr[1]=2;
        while(j<n)
        {
            if(arr[i]==2)
            {
                if(arr[j-1]==1)
                {
                    arr[j++]=2;
                    arr[j++]=2;
                }
                else
                {
                    arr[j++]=1;
                    arr[j++]=1;
                }
            }
            else
            {
                if(arr[j-1]==1)
                    arr[j++]=2;
                else
                    arr[j++]=1;
            }
            i++;
        }
        for(i=0;i<n;i++)
           count+=2-arr[i];
        // cout<<endl;
        return count;
    }
};