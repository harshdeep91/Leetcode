class Solution {
public:
    string reorderSpaces(string text) {
         int sp = 0,w = 0;
        string s = "";
        vector<string>v;
        
        for(int i = 0;i<text.size();i++)
        {
            if(text[i]>='a' && text[i]<='z') 
            {
                s += text[i];   
            }
            else
            {
                 sp++;
                if(s.size() != 0)
                {
                    w++;
                    v.push_back(s);
                    s = "";
                }
               
            }
            
        }
        string ans = "";
        if(s.size() != 0)
        {
             v.push_back(s);
             w++;
        }
        if(v.size() == 1 && sp == 0)
        {
            return v[0];
        }
        else if(v.size() == 1 && sp != 0)
        {
            ans += v[0];
            while(sp--)
            {
                ans += " ";
            }
            return ans;


        }
        int x = w-1;
        int y = sp/x;
        int z = y*x;
        int a = sp-z;
        
        for(int i = 0;i<v.size();i++)
        {
            ans += v[i];
            int j = y;
            while(j>0 && i<v.size()-1)
            {
                ans += " ";
                j--;
            }

        }
        while(a--)
        {
            ans += " ";
        }
        return ans; 
    }
};