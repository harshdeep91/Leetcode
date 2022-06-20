class Solution {
public:
    bool checkValidString(string s) {
        //lets first remove all * and store there index
        // store char and index in stack neutralised first
        //then use * if they are in range
        stack<pair<char,int>> st;
        vector<int> v;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
            {
                if(!st.empty()&&st.top().first=='(')
                    st.pop();
                else
                  st.push({s[i],i});
            }
            else if(s[i]=='(')
              st.push({s[i],i});
            else
                v.push_back(i);
            // cout<<s[i]<<" "<<i<<" ";
            // if(!st.empty()&&!v.empty())
            //     cout<<st.top().first<<" "<<st.top().second<<" "<<v.back();
            // cout<<endl;
        }
       cout<<st.size()<<" ";
        while(!st.empty()&&!v.empty())
        {
            // cout<<st.top().first<<" "<<st.top().second<<" "<<v.back();
            if(st.top().first=='(')//for this we want higher index star
            {
                if(v.back()<st.top().second)return 0;
                v.pop_back();
                st.pop();
            }
            else //for this lower index
            {
                while(!v.empty()&&v.back()>st.top().second)
                    v.pop_back();
                if(v.empty())return 0;
                st.pop();
                v.pop_back();
            }
        }
        // cout<<st.top().second<<endl;
        return st.empty();
    }
};