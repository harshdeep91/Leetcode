class Solution {
   unordered_set<string> m;
public:
    int solve(int x,int y,int i,int j,int k,vector<int> &commands)
    {
        //x=0 y=1 N 
        //x=-1 y=0 E
        //x=0  y=-1 S
        //x=1  y=0 W
        if(k==commands.size())
            return i*i+j*j;
        // cout<<x<<" "<<y<<" "<<i<<" "<<j<<" "<<commands[k]<<endl;
        //select command
        if(commands[k]==-2)//left
        {
            if(x==0)//N or S
                return y==1?solve(-1,0,i,j,k+1,commands):solve(1,0,i,j,k+1,commands);
            else//W or E
                return x==1?solve(0,1,i,j,k+1,commands):solve(0,-1,i,j,k+1,commands);
        }
        else if(commands[k]==-1)//right
        {
            if(x==0)//N or S
                return y==1?solve(1,0,i,j,k+1,commands):solve(-1,0,i,j,k+1,commands);
            else//W or E
                return x==1?solve(0,-1,i,j,k+1,commands):solve(0,1,i,j,k+1,commands);
        }
        else//move
        {
            int mx=i*i+j*j;
            while(commands[k]--)
            {
                string s=to_string(i+x)+"*"+to_string(j+y);
                if(m.find(s)!=m.end())//then only break;
                    break;
                i+=x,j+=y;
            }
            return max(mx,solve(x,y,i,j,k+1,commands));
        }
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        for(auto x:obstacles)
            m.insert(to_string(x[0])+"*"+to_string(x[1]));
        return solve(0,1,0,0,0,commands);
    }
};