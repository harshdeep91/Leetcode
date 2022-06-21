class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        //place ladder where difference is more
        //place bricks where dff is low
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<h.size()-1;i++)
        {
            if(h[i+1]-h[i]>0)//means required
            {
                int diff=h[i+1]-h[i];
                //check if max if yes then put ladd and remove previous low ladder
                if(l)
                {
                    l--;
                    q.push(diff);
                }
                else
                {
                    if(!q.empty()&&diff>q.top())//then put ladder here
                    {
                        b-=q.top();
                        q.pop();
                        if(b<0)return i; //we cant reach i+1
                        q.push(diff);
                    }
                    else //put bricks
                    {
                        b-=diff;
                        if(b<0)return i;
                    }
                }
                // cout<<diff<<" "<<b<<" "<<l<<" "<<i<<endl;
            }
        }
        return h.size()-1;
    }
};