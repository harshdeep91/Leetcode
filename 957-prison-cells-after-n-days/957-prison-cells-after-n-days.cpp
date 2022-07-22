class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        //there is only 6! combination
        vector<vector<int>> v;
        v.push_back(cells);
        cells[0]=0,cells[7]=0;
        while(n--)
        {
            int i=1;
            for(i=1;i<7;i++)
            cells[i]=v.back()[i-1]==v.back()[i+1];  
            v.push_back(cells);
            
            //now check if this is repeated with first
            for(i=1;i<7;i++)
            {
                if(v[1][i]!=v.back()[i])break;
            }
            if(v.size()>2&&i==7)//we found the repeated one
            {
                cout<<n<<" "<<v.size()-1<<" ";
                 return v[n%(v.size()-2)+1];
            }
            
        }
          
        return v.back();
    }
};