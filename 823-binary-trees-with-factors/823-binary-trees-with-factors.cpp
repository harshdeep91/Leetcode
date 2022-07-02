class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        //the answer is based on two for looops
        //simply sort and then store the counts of values
        //big tree could be made from small tree multiplication
        // we store the diff type of structure count
        unordered_map<long,long long> m;
        int mod=1e9+7;
        long long count=0;
        sort(arr.begin(),arr.end());
        for(auto x:arr)m[x]++;
        for(int i=0;i<arr.size();i++)
        {
            // cout<<arr[i]<<"==> ";
            for(int j=0;j<i;j++)
            {
                
                if(arr[i]%arr[j]==0)
                 m[arr[i]]+= ((long long)m[arr[j]]*m[arr[i]/arr[j]])%mod;
                // cout<<"("<<arr[j]<<" "<<m[arr[i]]<<") ,";
            }
            // cout<<endl;
        }
        for(auto x:m)
            count= (count+x.second)%mod;
        return count;
    }
};