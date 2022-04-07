class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        //use the map for overlapping coordinates
        //count the overlapping coordinates make their area as 1
        //subtract them from overall area of second rectangle
         int area1=(ax2-ax1)*(ay2-ay1),area2=(bx2-bx1)*(by2-by1),count=0;
        if(!area1||!area2)
            return area2?area2:area1;
        int firstrow=0,lastcol=0;
        bool row=0;
        for(int i=bx1;i<=bx2;i++)
        {
            for(int j=by1;j<=by2;j++)
            {
                if(i>=ax1&&i<=ax2&&j<=ay2&&j>=ay1)
                {
                    if(row==0)
                    {
                        row=1;
                        firstrow=i;
                        lastcol=j;
                    }
                    if(!row||(firstrow!=i&&lastcol!=j))
                    {
                        count++;
                        // cout<<i<<" "<<j<<" "<<count<<endl;
                    }
                }
            }
        }
        return area1+area2-count;
    }
};