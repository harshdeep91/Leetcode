class Solution {
public:
    int scoreOfParentheses(string ss) {
       //input is valid means there is equal left and right
        // only two pattern is coming ()() and (())
        // we simply push ( this and if ) comes then add one if immediate is ( otherwis multiply if value>0
        // ( => 0 and -1 => )
        stack<int> s;
        for(int i=0;i<ss.size();i++)
        {
            if(ss[i]=='(')s.push(0);
            else //because it is valid so stack is never be empty when )
            {
                if(s.top()==0)//(
                {
                    s.pop();
                    s.push(1);//() case
                    
                }
                else //theres a (A) case
                {
                    int val=s.top()*2; //(A
                    s.pop();// (
                    if(s.top()==0)s.pop();//
                    s.push(val);//2*A
                }
                    int val=0;
                    while(!s.empty()&&s.top()>0)val+=s.top(),s.pop();//normalize (()()) (11)=>(2)
                    s.push(val);
            }
        }
        return s.top();
    }
};