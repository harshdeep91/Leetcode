class Solution {
public:
    int minPartitions(string n) {
        //first value would be 
        //n-size(n (111))
        //need to carefully check when subtracting 11 or 10
        //31 => 31-11 => 20 => 20-11 => 9-1 till(9) = 11
        //31 => 31-11 => 20-10 => 20-10 = 3
        //what i observe here that
        //we start from first of from front(because we have two choices 0,1 but in back only 1)
        // 32 => now for 3 we need 3 times 1 so 3
        // now for 2 we need 2 ones => but we already used 3 ones so we can use 11,11,10 
        int mx=0;
        for(auto x:n)
            mx=max(x-'0',mx);
        return mx;
    }
};