class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        //count the up and down 
        // remove same face card as they never be good
        // travel in smallest card and try the up count to zero if pos
        map<int,int> up,down,same;
        for(int i=0;i<fronts.size();i++)
        {
            if(fronts[i]==backs[i])
            // up[fronts[i]]=INT_MIN,down[fronts[i]]=INT_MIN;
                same[fronts[i]]++;
            up[fronts[i]]++,down[backs[i]]++;
        }
        int mi=INT_MAX;
             for(auto x:down)
        {
            // cout<<x.first<<" "<<x.second<<endl;
            if(same[x.first]==0)//it means it is not same face 
            {
                mi=x.first;
                break;
            }
        }
        for(auto x:up)
        {
            // cout<<x.first<<" "<<x.second<<endl;
            if(same[x.first]==0)//it means it is not same face 
            {
                mi=min(mi,x.first);
            }
        }
       
        return mi==INT_MAX?0:mi;
    }
};