class Solution {
public:
    vector<string> letterCombinations(string digits) {
               vector<string>v;
        vector<string>phone = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.size() == 0)
            return v;                //23 
        v.push_back("");   
        
        for(auto digit : digits)
        {
            vector<string>temp;
            for(auto click : phone[digit-'0'])
            {
                for(auto x : v)
                {
                    temp.push_back(x+click);   // a b c
                }                             // def
                                             // ad bd cd 
                
            }
            v = temp;
        }
        return v;   

    }
};