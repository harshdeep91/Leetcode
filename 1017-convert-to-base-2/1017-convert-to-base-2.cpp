class Solution {
public:
    string baseNeg2(int n) {
        string ans;
        bool neg=0;
        //its the same as binary values but we only need to change
        //the last remainder is -1 or 1 if -1 then add 11 else 1
        while(n)
        {
            if(abs(n)%2==1)
            {
                ans.push_back('1');
                n= (n-1)/-2;
            }
            else
            {
                ans.push_back('0');
                n= n/-2;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans.size()?ans:"0";
    }
};