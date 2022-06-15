class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> r,d;
        int i;
        while(i<s.size())
            s[i]=='R'?r.push(i++):d.push(i++);
        
        while(!r.empty()&&!d.empty())
        {
                if(r.front()<d.front())
                r.push(i++);
            else
                d.push(i++);
            
                r.pop();
                d.pop();
        }
        return r.size()?"Radiant":"Dire";
    }
};