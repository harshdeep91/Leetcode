class Solution {
public:
    int calculate(string m) {
        stack<int> st;
        int k=0,sign=1,i=0;
        char calc='0';
        string s;
        for(int j=0;j<m.size();j++)
        {
            if(m[j]!=' ')
                s.push_back(m[j]);
        }
        while(i<=s.size())
        {
            if(i==s.size()||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
            {
                st.push(k*sign);
                k=0;
                if(i<s.size())
                sign=s[i]=='-'?-1:1;
                if(calc=='*'||calc=='/')
                {
                    int y=st.top();
                    st.pop();
                    int x=st.top();
                    st.pop();
                    if(calc=='*')
                        st.push(x*y);
                    if(calc=='/')
                        st.push(x/y);
                   
                }
                if(i<s.size())
                calc=s[i];
            }
            else
            {
                k*=10;
                k+=s[i]-'0';
            }
            // if(i<s.size())
            // cout<<s[i]<<" ";
            //    if(!st.empty())
            // cout<<st.top();
            // cout<<endl;
                i++;
        }
        int res=0;
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};