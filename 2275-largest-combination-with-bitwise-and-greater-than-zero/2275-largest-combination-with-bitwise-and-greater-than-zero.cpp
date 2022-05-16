class Solution {
public:
    int largestCombination(vector<int>& candidates) {
      vector<int> v(32,0);
        int mx=0;
        for(int i=0;i<candidates.size();i++)
        {
            int pos=31,temp=candidates[i];
            while(temp)
            {
                v[pos]+=temp&1;
                // cout<<temp<<" "<<pos<<endl;
                temp>>=1;
                pos--;
            }
        }
        for(int i=0;i<32;i++)
        {
            mx=max(v[i],mx);
        }
        return mx;
    }
};