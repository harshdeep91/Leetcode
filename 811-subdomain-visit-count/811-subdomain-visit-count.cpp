class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        //we are meging also
        //store count of every word
        // and start doing adding them in ans one by one
        //it will take size *3 time
        unordered_map<string,int> m;
        for(auto x:cpdomains)
        {
            for(int i=0;i<x.size();i++)
                if(x[i]=='.')x[i]=' ';
            // cout<<x<<endl;
            stringstream ss(x);
            int count;
            string a,b,c;
            ss>>count>>a>>b>>c;
            if(c.empty())
            {
                m[b]+=count;
                m[a+'.'+b]+=count;
            }
            else
            {
                m[c]+=count;
                m[b+'.'+c]+=count;
                m[a+'.'+b+'.'+c]+=count;
            }
        }
        vector<string> v;
        for(auto x:m)
        {
            v.push_back(to_string(x.second)+" "+x.first);
        }
        return v;
    }
};