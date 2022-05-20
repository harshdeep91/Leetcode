class Solution {
public:
    int bound(vector<pair<int,int>> &v,int val,int n){
    int l=0;int r=n;int mid;
        
    while(l<r){
        mid=(l+r)/2;
        
        if(v[mid].first>=val)r=mid;
        else l=mid+1;    
    }   
 return l<n ? v[l].second : -1;   
}
    
    
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
    int n=intervals.size();
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++){
          v.push_back({intervals[i][0],i}); 
        }
        
        sort(v.begin(),v.end());
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            int result=bound(v,intervals[i][1],n);
            ans.push_back(result);
        }
        
        
     return ans;   
    }
};