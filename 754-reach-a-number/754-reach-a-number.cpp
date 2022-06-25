class Solution {
public:
    int reachNumber(int target) {
     
        // see notes => by clicking in right side
        //every time extra values added 
        target=abs(target);
        int count=0,steps=0;
        if(target&1)//odd find value greater then or equal target but in odd way
        {
            while(count<target)
            {
                count+=++steps;
            }
            // cout<<count<<endl;
            while(!(count&1))//make it even by adding extra steps
                count+=++steps;
            
            return steps;
        }
        else
        {
            while(count<target)
            {
                count+=++steps;
            }
            while((count&1))//make it even by adding extra steps
                count+=++steps;
            return steps;
        }
        return 0;
    }
};