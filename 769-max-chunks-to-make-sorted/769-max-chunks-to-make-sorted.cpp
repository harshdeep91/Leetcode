class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<pair<int,int>> s;
        //in stack always bigger element is at top
        // we simply put elements in increasng order
        // notice 0 to n-1 
        // if smaller elements comes means they must be in previous parition because if take another partition after sorting it will not work
        
        for(int i=0;i<arr.size();i++)
        {
            int mx=-1,partition=0;
            while(!s.empty()&&s.top().first>arr[i])
            {
                mx=max(s.top().first,mx);
                partition=s.top().second;
                s.pop();
            }
            if(mx==-1)//means no prev value is greater
            {
                partition=s.empty()?1:s.top().second+1;
                s.push({arr[i],partition});
            }
            else
            {
                s.push({mx,partition});
            }
        }
        return s.size();
    }
};