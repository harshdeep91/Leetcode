class Solution {
public:
    bool isValidSerialization(string preorder) {
      int count = 0;
        for(int i = 0 ; i < preorder.size() ; i++){
            if(preorder[i] == ',') continue;
            
            if(count < 0) return false;
            
            if(preorder[i] == '#')
                count--;
            else{
                while(i < preorder.size() && preorder[i]!=','  )
                    i++;
                count++;
            }
                
        }
        if(count == -1) return true;
        return false;
        
    }
};