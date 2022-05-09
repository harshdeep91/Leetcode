class NestedIterator {
public:
    vector<int>v;
    void solve(vector<NestedInteger> &nestedList)
    {
        for(int i = 0;i<nestedList.size();i++)
        {
            if(nestedList[i].isInteger())
            v.push_back(nestedList[i].getInteger());
            else 
            solve(nestedList[i].getList());
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {

       solve(nestedList);
    }
    int i = 0;
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        if(i<v.size())
        return true;
        return false;
    }
};