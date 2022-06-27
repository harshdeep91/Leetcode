class Solution {
public:
    vector<int> partitionLabels(string s) {
        int a[256]={0},partition=1;
        vector<int> v,size;
        for(int i=0;i<s.size();i++)
        {
            // if(a[s[i]]==0)//never encountered before
            // {
            // }
            if(a[s[i]]!=0) //encountered before update every thing to same partition
            {
                
                partition=a[s[i]];
                // cout<<i<<" "<<s[i]<<" "<<partition<<" "<<a[s[size.back()]]<<" "<<size.back()<<" ";
                while(!size.empty()&&a[s[size.back()]]>=partition)
                    size.pop_back();
                
                 for(int j='a';j<='z';j++)
                     if(a[j]>partition)
                         a[j]=partition;
            }
            a[s[i]]=partition++;
            size.push_back(i);
            // cout<<size.back()<<endl;
        }
        int last=-1;
        // cout<<endl<<endl;
        for(int i=0;i<size.size();i++)
        {
            // cout<<size[i]<<" ";
            v.push_back(size[i]-last);
            last=size[i];
        }
        // cout<<endl;
        return v;
    }
};