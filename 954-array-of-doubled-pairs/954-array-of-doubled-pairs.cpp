class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        //arr lenth is even means there is always a even value in odd index
            vector<int> pos,neg;
            unordered_map<int,int> m;
            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]<0)
                    neg.push_back(arr[i]);
                else
                pos.push_back(arr[i]);
                m[arr[i]]++;
            }
            sort(neg.begin(),neg.end()),sort(pos.begin(),pos.end());
            for(int i=neg.size()-1;i>=0;i--)
                pos.push_back(neg[i]);
        //store the max element first 
        //simply find if it is possible to get val,2*val pairs
        

        for(int i=0;i<pos.size();i++)
        {
            if(m[pos[i]])
            {
                if(m[2*pos[i]])
                {
                    m[pos[i]]--;
                    m[2*pos[i]]--;
                }
                else return 0;
            }
            
        }
        return 1;
    }
};