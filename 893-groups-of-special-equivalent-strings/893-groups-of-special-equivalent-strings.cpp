class Solution {
public:
    void convert(string &a)//converting to sorted even and odd
    {
        string even,odd;
        bool flag=1
            ;
        for(int i=0;i<a.size();i++)
        {
            if(flag)//even
                even.push_back(a[i]);
            else
                odd.push_back(a[i]);
            flag=!flag;
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        a=even+odd;
    }
    int numSpecialEquivGroups(vector<string>& words) {
        //Brute Force= check by 2 for loops N*k*N*k
        // sort by even and odd index ,sort main string,sliding window,nklogk
        // we can also store count in even and odd index and check
        for(int i=0;i<words.size();i++)
            convert(words[i]);
         sort(words.begin(),words.end());
        unordered_map<string,int> m;
        for(auto x:words)
            m[x]++;
        return m.size();
    }
};