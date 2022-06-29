class Solution {
public:
    int rotatedDigits(int n) {
       //0,1,8 does not affeect
        // 2,5 => 5,2
        //6 9 => 9,6
         //        0,1,2, 3, 4,5,6, 7,8,9
        int a[10]={0,0,1,-1,-1,1,1,-1,0,1},count=0,val,tmp,t,diff;
        // invalid =-1 ,diff =2 ,same=1
        for(int i=1;i<=n;i++)
        {
            val=i,tmp=0,diff=0;
            while(val)
            {
                t=val%10;
                if(a[t]==-1)
                {
                    tmp=0;
                    break;
                }
                tmp|=a[t];
                val/=10;
            }
            // tmp--;
            // cout<<i<<" "<<tmp<<" "<<diff<<" "<<count<<endl;
            count+=tmp;
        }
        return count;//-1 because the same digit also getting counted
    }
};