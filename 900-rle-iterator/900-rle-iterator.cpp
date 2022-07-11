class RLEIterator {
    vector<int> ans;
    int i=0;
public:
    //brute force approach is decode to normal array and do
    // simple approach is do solution in encoding
    RLEIterator(vector<int>& encoding) {
        ans=encoding;
    }
    
    int next(int n) {
        
        while(i<ans.size()&&n)
        {
            if(n>ans[i])
            {
                n-=ans[i];
                i+=2;
            }
            else if(n<ans[i])
            {
                ans[i]-=n;
                n=0;
            }
            else //n===ans[i] in this increase i+=2 but return  ans[i+1]
            {
                int last=ans[i+1];
                i+=2;
                return last;
            }
        }
        return i<ans.size()?ans[i+1]:-1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */