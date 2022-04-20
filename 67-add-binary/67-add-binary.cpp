class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()>b.size())
            return addBinary(b,a);
        if(a.size()<b.size())
        {
            reverse(a.begin(),a.end());
            while(a.size()<b.size())
                a.push_back('0');
            reverse(a.begin(),a.end());
        }
            
        int i=a.size()-1,carry=0;
        string ans;
        // cout<<a<<" "<<b<<endl;
        while(i>=0)
        {
            // cout<<carry<<" ";
            if(a[i]=='1'&&b[i]=='1')
            {
                if(carry)
                ans.push_back('1');
                else
                {
                    ans.push_back('0');
                    carry=1;
                }
            }
            else if(a[i]=='0'&&b[i]=='0')
            {
                if(carry)
                {
                    ans.push_back('1');
                    carry=0;
                }
                else
                    ans.push_back('0');
            }
            else
            {
                if(carry)
                    ans.push_back('0');
                else
                {
                    ans.push_back('1');
                    carry=0;
                }
            }
            // cout<<ans<<" "<<i<<endl;
            i--;
        }
        // cout<<carry<<" ";
        if(carry)
            ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};