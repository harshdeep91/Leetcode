class Solution {
public:
    bool reorderedPowerOf2(int n) {
        //simply count the digit 
        //and find all possilble power of 2 value in that no digit
        //check one by one by map
        int size=to_string(n).size();
        int val=1;
        while(to_string(val).size()<size)val*=2;//now this will take us to the first value in that size
        int m[10]={0};
        for(auto x:to_string(n))m[x-'0']++;
        while(to_string(val).size()<=size)
        {
            string t=to_string(val);
            int k[10]={0},i=0;
            for(auto x:t)k[x-'0']++;
            //if m==k then its the ans
            while(i<10&&m[i]==k[i])i++;
                if(i==10)return 1;
            val*=2;
        }
        return 0;
    }
};