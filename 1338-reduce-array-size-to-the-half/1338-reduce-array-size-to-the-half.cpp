class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int,int>> q;
        unordered_map<int,int> m;
        for(auto x:arr)m[x]++;
        for(auto x:m)q.push({x.second,x.first});
        int req=0,count=0;
        while(!q.empty()&&req<arr.size()/2)
        {
            count++;
            req+= q.top().first;
            q.pop();
        }
        return count;
    }
};