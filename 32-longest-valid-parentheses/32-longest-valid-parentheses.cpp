class Solution {
public:
    
         int longestValidParentheses(string s) {
        stack <int> stk;
        int n = s.length();
        int ans = 0;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')'){
                if (stk.size() > 0) {
                    ans =ans + 1 + stk.top();
                    stk.pop();
                    
                    ret = max(ret, ans);
                } else {
                    ans = 0;
                }
            } else {
                stk.push(ans + 1);ans = 0;
            }
        }
        return ret;
    }
}; 

//put stack top the ans