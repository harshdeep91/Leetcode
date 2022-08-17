class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string a[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> s;
        
        for(auto x:words)
        {
            string p;
            for(int i=0;i<x.size();i++)
                p+=a[x[i]-'a'];
            s.insert(p);
        }
        return s.size();
        
    }
};