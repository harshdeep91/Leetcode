
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string> s;
        string p;
for(long long int i=1;i<INT_MAX;i*=2)
{
    p=to_string(i);
    sort(p.begin(),p.end());
    s.insert(p);
};
    p=to_string(n);
        sort(p.begin(),p.end());
        return s.count(p);
    }
};