class Solution {
public:
    int countBinarySubstrings(string s) {
        int count0=0,count1=0,count=0,i=0;
        bool zero=s[0]=='0'?1:0;
        while(i<s.size())
        {
            
            if(s[i]=='0')
            { 
                //check for middle one 0010
                
                if(count0&&!zero)
                    count0=0;
                    zero=1;
                count0++;
                if(count1)
                {
                    count1--;
                    count++;
                }
            }
            else
            {
                if(count1&&zero)//checking for middle zero 11011
                    count1=0;
                     zero=0;
                 
                count1++;
                if(count0)
                {
                    count0--;
                    count++;
                }
            }
            i++;
        }
        return count;
    }
};