class Solution {
    vector<int> ans;
public:
    bool solve(int i,string &num,int prev,int prevprev)
    {
        // if((long long)prev+prevprev>=INT_MAX)return 0;
        // cout<<i<<" "<<prev<<" "<<prevprev<<endl;
        if(i==num.size()&&ans.size()>=3)
        {
            return true;
        }
        //if first means prev and prevprev not assigned then choose any values
        long long val=0,sum=(long long)prev+prevprev;
        //if leading zero then only one time it should run
        if(num[i]=='0')
        {
              if(prev==-1||prevprev==-1||val==sum)
              {
                 ans.push_back(val);
                if(solve(i+1,num,val,prev))
                    return true;
                 ans.pop_back(); 
              }
            return 0;
        }
            
        for(int j=i;j<num.size();j++)
        {
            val*=10;
            val+= num[j]-'0';
            if(val>=INT_MAX)return 0;
            if(prev==-1||prevprev==-1||val==sum)
            {
                ans.push_back(val);
                if(solve(j+1,num,val,prev))
                    return true;
                 ans.pop_back();
            }
        }
        return 0;
    }
    vector<int> splitIntoFibonacci(string num) {
        //1101111
        //first choose number
        //it should satisfy previous two sum 
        //if it is saller we increase number
        solve(0,num,-1,-1);
        return ans;
    }
};