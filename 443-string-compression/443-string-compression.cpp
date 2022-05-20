class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,j=0,count=0,len=0,rev,count_zero;
        while(j<chars.size())
        {
            
            while(j<chars.size()&&chars[i]==chars[j])
            {
                count++;
                j++;
            }
            // cout<<i<<" "<<j<<" "<<count<<endl;
            chars[len++]=chars[i];
            if(count>1)//means only group
            {
                //reverse count
                rev=0,count_zero=0;
                while(count%10==0)
                    count_zero++,count/=10;
                while(count)
                {
                    rev*=10;
                    rev+=count%10;
                    count/=10;
                }
                // cout<<rev<<" "<<len<<endl;
                // insert in string
                while(rev)
                {
                    chars[len++]=rev%10+'0';
                    // cout<<rev%10<<" "<<len<<endl;
                    rev/=10;
                }
                while(count_zero)
                    chars[len++]='0',count_zero--;
            }
            count=0;
            i=j;
        }
      return len;  
    }
};