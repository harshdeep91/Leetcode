class MyCircularDeque { 
    vector<int> q;
    int f=0,l=1;
public:
    MyCircularDeque(int k) {
        q.resize(k+1,0);
    }
    
    bool insertFront(int value) {
        if(!isFull())
        {
            q[f]=value;
            f=(f-1+q.size())%q.size();
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(!isFull())
        {
            q[l]=value;
            l=(l+1)%q.size();
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(!isEmpty())
        {
            f=(f+1)%q.size();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(!isEmpty())
        {
            l=(l-1+q.size())%q.size();
            return true;
        }
        return false;
    }
    
    int getFront() {
        int x=-1;
        if(!isEmpty())
        {
            x=q[(f+1)%q.size()];
        }
        return x;
    }
    
    int getRear() {
        int x=-1;
        if(!isEmpty())
        {
            x=q[(l-1+q.size())%q.size()];
        }
        return x;
    }
    
    bool isEmpty() {
        return (f+1)%q.size()==l;
    }
    
    bool isFull() {
        return f==l;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */