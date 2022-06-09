class Solution {
public:
    int nextGreaterElement(int n) {
         // stack<int> s;
        string p=to_string(n);
        //small index, greater index;
        int i=p.size()-2,j=p.size()-1;
        while(i>=0&&p[i]>=p[i+1])
            i--;
        if(i<0)return -1;
        while(j>i&&p[j]<=p[i])
            j--; 
            
        swap(p[i],p[j]);
        reverse(p.begin()+i+1,p.end());
            long long c=stol(p);
            return c>INT_MAX?-1:(int)c;
    }
};