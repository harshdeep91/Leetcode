typedef pair<double,pair<int,int>> pp;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        //find prefix sum 
        priority_queue<pp,vector<pp>,greater<pp>> q;
        
        for(int i=0;i<arr.size()-1;i++)
            q.push({(double)arr[i]/arr.back(),{arr[i],arr.size()-1}});
        while(--k)
        {
             pp g=q.top();
             q.pop();
             int index=g.second.second-1;
             int val=g.second.first;
             if(index>=0)
             q.push({(double)val/arr[index],{val,index}});
             
        }
        
        return  {q.top().second.first,arr[q.top().second.second]};
    }
};
