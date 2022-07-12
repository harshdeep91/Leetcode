class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       //find the array possible from i from each sides
        // so for that we will find next and prev minima
        stack<pair<int,int>> s; //value,index
        vector<int> left(arr.size()),right(arr.size());
        for(int i=0;i<arr.size();i++)
        {
            left[i]=i;
            while(!s.empty()&&s.top().first>=arr[i])
                left[i]=s.top().second,s.pop();
            s.push({arr[i],left[i]});
            // cout<<left[i]<<" ";
        }
        cout<<endl;
        while(!s.empty())s.pop();
        for(int i=arr.size()-1;i>=0;i--)
        {
            right[i]=i;
            while(!s.empty()&&s.top().first>arr[i])
                right[i]=s.top().second,s.pop();
            s.push({arr[i],right[i]});
            
        }
        // for(int i=0;i<arr.size();i++)
        //   cout<<right[i]<<" ";
        // cout<<endl;
        //calculate now
        long long ans=0,mod=1e9+7,l,r;
        for(int i=0;i<arr.size();i++)
        {
            l=i-left[i],r=right[i]-i;
            ans= (ans+arr[i]*(l+r+l*r+1))%mod;
        }
        return ans;
    }
};