class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> v;
        unordered_set<int> m;
        v.push_back(1);
        m.insert(1);
        bool flag=1; //add k
        while(k)
        {
            if(flag)
            v.push_back(v.back()+k);
                else v.push_back(abs(v.back()-k));
            m.insert(v.back());
            k--;
            flag=!flag;
        }
        int count=v.back()+1;
        while(m.find(count)!=m.end())
            count++;
        while(v.size()<n)
        {
            v.push_back(count);
            count++;
        }
        return v;
    }
};