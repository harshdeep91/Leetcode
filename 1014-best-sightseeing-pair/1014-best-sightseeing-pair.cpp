class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //maximum score will be find out when two max value used
        //maximum value is possible when left is max and right is also max
        vector<int> f,s;
        for(int i=0;i<values.size();i++)f.push_back(values[i]+i),s.push_back(values[i]-i);
        int mx=f[0];
        for(int i=1;i<values.size();i++)
        {
            if(f[i]>mx)
                mx=f[i];
             else
                 f[i]=mx;
               
        }
        for(int i=0;i<values.size();i++)cout<<f[i]<<" ";
        cout<<endl;
        mx=s.back();
        for(int i=s.size()-2;i>=0;i--)
        {
            if(s[i]>mx)
                mx=s[i];
             else
                 s[i]=mx;
        }
        for(int i=0;i<values.size();i++)cout<<s[i]<<" ";
        cout<<endl;
        mx=0;
        for(int i=0;i<values.size()-1;i++)
            mx=max(mx,f[i]+s[i+1]);
        return mx;
    }
};