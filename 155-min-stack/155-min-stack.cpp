class MinStack {
    stack<int> s,t,k;
    map<int,int> m;
public:
    MinStack() {
        
    }
    
    void push(int val) {
       s.push(val);
       m[val]++;
        // while(!t.empty()&&t.top()<val)
        //     k.push(t.top()),t.pop();
        //  t.push(val);
        // while(!k.empty())
        //     t.push(k.top()),k.pop();
        // cout<<val<<" "<<t.top()<<endl;
        
    }
    
    void pop() {
        m[s.top()]--;
        s.pop();
    }
    
    int top() {
        return  s.top();
    }
    
    int getMin() {
        for(auto x:m)
            if(x.second!=0)return x.first;
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */