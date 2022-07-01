class Solution {
public:
    double champagneTower(int p, int x, int y) {
        // 100,100
        // we see that for every champagne 
        //it will flow to half half both sides
        //we can use queue for this because for getting on
        //value we need last two half added
        queue<double> q;
        q.push(p);
        double row=0,col=0,last,size,t,j;
        while(!q.empty()&&row<=x)
        {
            
            size=q.size(),last=0,col=0;
            // cout<<size<<" "<<corner<<endl;
            while(size--)
            {
                t=q.front(); q.pop();
                // cout<<row<<" "<<col<<" "<<last<<" "<<t<<endl;
                if(row==x&&col==y)
                    return t>1?1:t;
                t=t-1>0?t-1:0;//because 1 liquid is remained
                j=(last+t)/2;//next element will be half of both thing added
                 q.push(j);
                 last=t;
                 col++;   
            }
            q.push(q.front());
            row++;
        }
        return 0;
    }
};