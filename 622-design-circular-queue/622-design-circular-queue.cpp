class MyCircularQueue {
    vector<int> q;
    int f=0,l=1,size;
public:
    MyCircularQueue(int k) {
        q.resize(k+1);
        size=k+1;
    }
    // void print()
    // {
    //     cout<<f<<" "<<l<<endl;
    //     for(auto x:q)cout<<x<<" ";
    //     cout<<endl;
    // }
    bool enQueue(int value) {
       if(!isFull())
        {
           q[l]=value;
            l=(l+1)%size;
            // print();
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty())
        {
            f=(f+1)%size;
            // print();
             return true;
        }
        return false;
    }
    
    int Front() {
        if(!isEmpty())
        {
            // print();
            return q[(f+1)%size];
        }
        return -1;
    }
    
    int Rear() {
        if(!isEmpty())
        {
            int t=l-1;
            if(t<0)t=size-1;
            // print();
            return q[t];
        }
        return -1;
    }
    
    bool isEmpty() {
        return  (f+1)%size==l;
    }
    
    bool isFull() {
        return f==l;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */