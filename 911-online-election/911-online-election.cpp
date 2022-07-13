class TopVotedCandidate {
    unordered_map<int,int> m;
    vector<pair<int,int>> v;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        //assign the votes based on times for ans find lower   bound
        int mx=0,person=0;
        for(int j=0;j<times.size();j++)
        {
            m[persons[j]]++;
            if(m[persons[j]]>=m[person])//means this person is the maximum
                person=persons[j];
            persons[j]=person;
            v.push_back({times[j],persons[j]});
        }
    }
    
    int q(int t) {
        //lower bound
        pair<int,int> x={t,INT_MIN};
        auto it =lower_bound(v.begin(),v.end(),x)-v.begin();
        // cout<<it<<" ";
        if(it>v.size()||v[it].first!=t)
            it--;
        return v[it].second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */