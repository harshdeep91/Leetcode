class MyCalendar {
    set<pair<int,int>> s;
    unordered_map<int,int> m;
    // set<int> s;
public:
    //insert end start as this will maintain sortest end first
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int,int> x={end,start};
        // s.insert(x);
        auto ss=lower_bound(s.begin(),s.end(),x);
        auto ff=s.begin();
            for(auto it=s.begin();it!=ss;it++)
            {
                ff=it;
            }
        // cout<<ff->second<<" "<<ss->second<<endl;
        // int t=ff-s.begin();
        if((ss==s.begin()&&end<=ss->second)||(ss==s.end()&&start>=ff->first)||end<=ss->second&&start>=ff->first)
        {
            s.insert(x);
            // cout<<x.second<<" "<<x.first<<endl;
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */