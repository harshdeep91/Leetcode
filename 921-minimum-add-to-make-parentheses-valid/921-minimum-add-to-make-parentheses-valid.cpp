class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count=0;
        for(auto x:s)
        {
            if(x==')')
            {
                if(st.empty())count++;
                else st.pop();
            }
            else 
            {
                st.push(x);
            }
        }
        return count+st.size();
    }
};