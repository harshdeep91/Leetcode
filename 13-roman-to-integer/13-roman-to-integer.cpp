class Solution {
public:
    int romanToInt(string s) {
        //the pattern mostly follows
        //first is big char then we need to add other 
        //values
        //big to small add 
        //small to big subtract the smalll from big
        //small is placed only 1 time before big
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int count=0,i=0,x,y;
        while(i<s.size()-1)
        {
             
            x=m[s[i]],y=m[s[i+1]];
            
             count+=(x>=y)?x:-x;
            // cout<<x<<" "<<count<<endl;
             i++; 
        }
        // x=m[s[i]],y=m[s[i-1]];
        count+=m[s[i]];//(x<=y)?x:-x;
        return count;
    }
};