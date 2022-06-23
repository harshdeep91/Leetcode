class MinStack {
    stack<int> s;
    map<int,int> m;
public:
    MinStack() {
        
    }
    
    void push(int val) {
       s.push(val);
       m[val]++;  
    }
    
    void pop() {
        m[s.top()]--;
        if(m[s.top()]==0)m.erase(s.top());
        s.pop();
    }
    
    int top() {
        return  s.top();
    }
    
    int getMin() {
        return m.begin()->first;
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