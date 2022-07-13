class Solution {
    
public:
    int sort(int l,int h,vector<int> &nums)
    {
        int pivot=nums[l],index=l;
        //now normalise it 
        while(l<=h)
        {
            do{l++;}while(l<h&&nums[l]<pivot);//l will point to greater element
            do{h--;}while(l<=h&&nums[h]>pivot);
            if(l<h)//then only swap
                swap(nums[l],nums[h]);
        }
        //now final swap
        swap(nums[index],nums[h]);
        return h;
    }
    void quicksort(int l,int h,vector<int> &nums)
    {
        // cout<<l<<h;
        if(l<h)
        {
            
            int j=sort(l,h,nums);
            // cout<<l<<" "<<h<<" "<<j<<endl;
            // for(auto x:nums)cout<<x<<" ";
            // cout<<endl;
            quicksort(l,j,nums);
            quicksort(j+1,h,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
       //quick sort
        int i=0;
        while(i+1<nums.size()&&nums[i]<nums[i+1])i++;
        if(i+1<nums.size())quicksort(0,nums.size(),nums);
        return nums;
    }
};