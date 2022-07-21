class Solution {
public:
    static bool cmp(int a,int b)
    {
        if(a<0&&b<0)
            return a>b;
        else
            return a<b;
            
    }
    bool canReorderDoubled(vector<int>& arr) {
        //arr lenth is even means there is always a even value in odd index
            unordered_map<int,int> m;
            sort(arr.begin(),arr.end(),cmp);
            for(int i=0;i<arr.size();i++)m[arr[i]]++;
        //store the max element first 
        //simply find if it is possible to get val,2*val pairs
        

        for(int i=0;i<arr.size();i++)
        {
            if(m[arr[i]])
            {
                if(m[2*arr[i]])
                {
                    m[arr[i]]--;
                    m[2*arr[i]]--;
                }
                else return 0;
            }
            
        }
        return 1;
    }
};