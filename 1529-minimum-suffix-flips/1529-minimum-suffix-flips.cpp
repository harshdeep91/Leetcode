class Solution {
public:
    int minFlips(string target) {
        int i=0,count=0;
        while(target[i]=='0'&&i<target.size())
            i++;
        while(i<target.size())
        {
            if(target[i]=='1')
            {
                while(i<target.size()&&target[i]=='1')
                     i++;
            }
            else
            {
                 while(i<target.size()&&target[i]=='0')
                     i++;
            }
            count++;
        }
        return count;
    }
};