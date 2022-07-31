class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottom) {
        int mi=INT_MAX;
        for(int domino=1;domino<=6;domino++)
        {
            int count1=0,count2=0;
            for(int i=0;i<tops.size();i++)
            {
                if(tops[i]!=domino)//simply swap
                {
                    if(bottom[i]==domino)
                        count1++;
                    else //it is not possible
                        count1=tops.size()+1;
                }
                if(bottom[i]!=domino)
                {
                    if(tops[i]==domino)
                        count2++;
                    else //it is not possible
                        count2=tops.size()+1;
                }
                
            }
            mi=min(mi,min(count1,count2));
        }
        return mi>tops.size()?-1:mi;
    }
};