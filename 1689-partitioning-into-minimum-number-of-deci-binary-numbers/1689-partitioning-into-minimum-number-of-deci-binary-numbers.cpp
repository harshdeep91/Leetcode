class Solution {
public:
    int minPartitions(string n) {
        //first value would be 
        //n-size(n (111))
        //need to carefully check when subtracting 11 or 10
        //31 => 31-11 => 20 => 20-11 => 9-1 till(9) = 11
        //31 => 31-11 => 20-10 => 20-10 = 3
        //means we either have two options
        // 131=>131-111 => 20 =>
        // we can store min for 2 digits values
        //find for other
        //934=> 234-111=> 123 -111=> 012=>
        int mx=0;
        for(auto x:n)
            mx=max(x-'0',mx);
        return mx;
    }
};