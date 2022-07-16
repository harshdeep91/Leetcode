class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        //first make map on identifier
        //sort the letter logs first
        //insert the letter logs in ans and after that digit logs
        vector<string> digits,ans;
        vector<pair<string,string>> v;
        // unordered_map<string,string> m;
        for(auto x:logs)
        {
             int i=0;
             while(i<x.size()&&x[i]!=' ')i++;
             if(x[i+1]>='a'&&x[i+1]<='z')//letter logs
             v.push_back({x.substr(i+1),x.substr(0,i)});
             else digits.push_back(x);
        }
        sort(v.begin(),v.end());
        
        for(auto x:v)
        {
            ans.push_back(x.second+" "+x.first);
            // cout<<x.first<<"-->"<<x.second<<endl;
        }
        for(auto y:digits)ans.push_back(y);
            // ans.(digits.begin(),digits.end());
        
       return ans;
    }
};