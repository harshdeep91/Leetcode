class StockSpanner {
    stack<pair<int,int>> s;
public:
    //compress because 70 after 60 is same as 70,2
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=1;
        while(!s.empty()&&s.top().first<=price)
        {
            count+=s.top().second;
            s.pop();
        }
        s.push({price,count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */