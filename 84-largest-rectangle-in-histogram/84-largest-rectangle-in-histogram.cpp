class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        int left[n],right[n],area=0;
        stack<int> s;
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty()||arr[s.top()]<arr[i])
                right[i]=i;
            else
            {
                while(!s.empty()&&arr[s.top()]>=arr[i])
                {
                    right[i]=right[s.top()];
                    s.pop();
                }
                if(s.empty())
                right[i]=n-1;
            }
            s.push(i);
        }
        while(!s.empty())
        s.pop();
        for(int i=0;i<n;i++)
        {
            if(s.empty()||arr[s.top()]<arr[i])
                left[i]=i;
            else
            {
                while(!s.empty()&&arr[s.top()]>=arr[i])
                {
                    left[i]=left[s.top()];
                    s.pop();
                }
                if(s.empty())
                left[i]=0;
            }
            s.push(i);
            // cout<<left[i]<<" ";
        }
        
        for(int i=0;i<n;i++)
        {
            area=max(area,(right[i]-left[i]+1)*arr[i]);
        }
        // cout<<endl;
        return area;
    }
};