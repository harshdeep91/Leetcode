class Solution {
    vector<int> ans;
public:
    bool solve(int i,string &num,int prev,int prevprev)
    {
        if(i==num.size()&&ans.size()>=3)
            return true;
        long long val=0;
        bool lead=num[i]!='0';
        
        do
        {
            val*=10;
            val+= num[i]-'0';
            if(val>=INT_MAX)return 0;
            if(prev==-1||prevprev==-1||val==(long long)prev+prevprev)
            {
                ans.push_back(val);
                if(solve(i+1,num,val,prev))
                    return true;
                 ans.pop_back();
            }
            i++;
        }while(lead&&i<num.size());//if leading zero then only one time it should run
        return 0;
    }
    vector<int> splitIntoFibonacci(string num) {
        solve(0,num,-1,-1);
        return ans;
    }
};