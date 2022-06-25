class Solution {
public:
    int reachNumber(int target) {
     
        // see notes => by clicking in right side
        //every time extra values added 
        target=abs(target);
        int count=0,steps=0;
        while(count<target||((target&1)&&!(count&1))||(!(target&1)&&(count&1)))
            count+=++steps;
            return steps;
    }
};