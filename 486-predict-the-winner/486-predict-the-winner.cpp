class Solution {
    bool player1;
public:
    int solve(int i,int j,vector<int> &nums)//[i,j] Not (i,j)
    {
        // cout<<one<<" "<<i<<" "<<j<<" "<<endl;
        if(i>j)//array ends
        {
            
            // cout<<"REturning\n";
            return 0;
            // nums[i];
        }
        
    
        // choose first or last
        //one=> player 1 turn
        // if(one)                //this should return one turne
        int x=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int y=nums[j]+min(solve(i,j-2,nums),solve(i+1,j-1,nums));
         // cout<<one<<" "<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<z<<endl;
        
        return max(x,y);
        // else
        //     return min(nums[i]+solve(1,i+1,j,nums),nums[j]+solve(1,i,j-1,nums));
    }
    bool PredictTheWinner(vector<int>& nums) {
        //max number
        //choose first or last
        //after removing all element check if player 1 can win
        //for one to win he should pick element such that next two is small
        //one must pick that element when picking to it b loose
        //i,j => nums[i]+min(solve(b))
        
        int x= solve(0,nums.size()-1,nums),sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        // cout<<x<<" "<<sum<<" "<<sum-x<<endl;
        return x>=sum-x;
    }
};

//error i have done => return made bool 
//for player to win it must choose the maxsum =>
// for that A first choose any number then b will choose maxsum => for that A must choose min number