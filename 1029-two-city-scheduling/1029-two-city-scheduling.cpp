class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //sort by savings 
        for(int i=0;i<costs.size();i++)
            costs[i]={costs[i][1]-costs[i][0],costs[i][0],costs[i][1]};
            sort(costs.begin(),costs.end(),greater<vector<int>>());
        int sum=0,count=0;
        for(int i=0;i<costs.size();i++)
          sum+= ++count<=costs.size()/2?costs[i][1]:costs[i][2];  
        return sum;
    }
};