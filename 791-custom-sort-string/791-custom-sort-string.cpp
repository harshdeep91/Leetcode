// class cmp{
//     public:
//     bool operator()(char x,char y)
//     {
//         return x<y;
//     }
// };


class Solution {
    // static int a[26];
public:
    // static bool cmp(char &x,char &y){
    //     return a[x]<a[y];
    // }
    string customSortString(string order, string s) {
        int a[26];
        for(int i=0;i<26;i++)a[i]=201;
        for(int i=0;i<order.size();i++)
        {
            if(a[order[i]-'a']==201)
                a[order[i]-'a']=i;
        }
        // priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>q;
        // for(auto x:s)
        //     q.push({a[x-'a'],x});
        // s.clear();
        // while(!q.empty())
        // {
        //     s.push_back(q.top().second);
        //     q.pop();
        // }
        sort(s.begin(),s.end(),[&](char &x,char &y){return a[x-'a']<a[y-'a'];});
        return s;
    }
};