class Solution {
public:
    string DToB(int num)
{
    string str;
      while(num){
      if(num & 1) // 1
        str+='1';
      else // 0
        str+='0';
      num>>=1; // Right Shift by 1 
    }   
      return str;
}
 
    bool queryString(string s, int n) {
        
        for(int i=1;i<=n;i++){
            string x=  DToB(i);
            // cout<<i<<" "<<x<<endl;
            reverse(x.begin(),x.end());
            if (s.find(x) == -1) return false;
   
        }   
         return true;
    }
   
};