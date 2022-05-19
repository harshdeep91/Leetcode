class Solution {
public:
    string originalDigits(string s) {
         
        int count[256]={0};
        for(char c : s) count[c]++;
        
        int num[10]={0};
        
        //Unique Cases
        num[0] = count['z'];
        num[2] = count['w'];
        num[4] = count['u'];
        num[6] = count['x'];
        num[8] = count['g'];
        
        //Derived Cases
        num[1] = count['o']-num[0]-num[2]-num[4];
        num[3] = count['h']-num[8];
        num[5] = count['f']-num[4];
        num[7] = count['s']-num[6];
        num[9] = count['i']-num[5]-num[6]-num[8];
        string sb;
        for(int i = 0; i < 10; i++){
            while(num[i]-- > 0)
                sb.push_back(i+'0');
        }
        return sb;
    }
};