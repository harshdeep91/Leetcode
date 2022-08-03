class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==1)return 1;
          int n=0,carry=0,end=1e7,prev=0;
        do
        {
            prev= (carry*10+1)%k;
            n++;
            // cout<<prev<<" "<<carry<<endl;
            if(prev==carry)return -1;
            carry=prev;
        }while(n<end&&carry);
        return n<end?n:-1;
    }
};