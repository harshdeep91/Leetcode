class TimeMap {
    unordered_map<string,vector<pair<int,string>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        pair<int,string> p= {timestamp,""};
        //find the pair
        auto it= lower_bound(m[key].begin(),m[key].end(),p)-m[key].begin();
        if(it<m[key].size()&&m[key][it].first==timestamp)
            return m[key][it].second;      
        it--;
            return  (it>=0)?m[key][it].second:"";
        
//         // cout<<it<<" ";
//         // return "" ;
        // if(it->first==timestamp)return it->second;
        // if(it==m[key].begin())return "";
        // it= prev(it);
        // return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */