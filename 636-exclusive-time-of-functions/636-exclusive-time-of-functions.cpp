class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        //what i found out that it is a normal stack question 
        //we simply insert id and if new id comes we will make timer - the new start time
        //if end id come we need to assign end-timer+1 because 
        //it will also consume the end time
        stack<int> s;
        vector<int> v(n,0);
        int timer=0;
        char j,q;
        
        for(auto x:logs)
        {
            int i=0,id=0,time=0;
            while(x[i]!=':')id*=10,id+=x[i++]-'0';
            j=x[++i];
            while(x[i++]!=':');
            while(i<x.size())time*=10,time+=x[i++]-'0';
            
            if(s.empty())
                s.push(id);
            else
            {
                if(j=='s')//start of new id simply do start-timer
                {
                    v[s.top()]+= time-timer;
                    timer=time;
                    s.push(id);
                }
                else
                {
                    v[s.top()]+=time-timer+1;
                    timer=time+1;
                    s.pop();
                }
            }
            
            // cout<<id<<" "<<j<<" "<<time<<endl;
        }
        return v;
    }
};