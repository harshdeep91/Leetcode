class Solution {
public:
    bool canMeasureWater(int j1, int j2, int target) {
if(j1+j2<target) return false;
        
        if(j1==target or j2==target) return true;
        
        unordered_map <int,int> mp;
        queue <int> q;
        q.push(0);
        while(!q.empty()){
            int filled = q.front();
            q.pop();
            
            if(filled == target) return true;
            
			// Maintaining a visited Data Structure to avoid TLE
            if(mp[filled]>0) continue;
            
            mp[filled] = 1;
                
            if(filled+j1<=j1+j2)
                q.push(filled+j1);
            if(filled-j1>=0)
                q.push(filled-j1);
            if(filled+j2<=j1+j2)
                q.push(filled+j2);
            if(filled-j2>=0)
                q.push(filled-j2);
        }
        return false;
    }
};