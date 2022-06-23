
    class Node {
        
        public:
        int val;
        int min;
        Node *next;
            
        Node(int val, int min, Node *next) {
            this->val = val;
            this->min = min;
            this->next = next;
        }
    };
class MinStack {
    private:
    Node *head=0;
        
    public:
    void push(int x) {
        if (!head) 
            head = new Node(x, x, 0);
        else 
            head = new Node(x, min(x, head->min), head);
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }
        
    
    
};