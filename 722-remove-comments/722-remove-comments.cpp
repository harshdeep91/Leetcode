class Solution {
public:
    vector<string> removeComments(vector<string>& s) {
        //  //remove directly  store extra string befor //
        // /* remove whole lines till * /  same store before /* and after */ 
        vector<string> v;
        int i=0,comment=0,j=0;
        //check two characters
        string block="/*",dbl="//",end="*/";
        // cout<<block<<" "<<dbl<<endl;
        string prev;
        while(i<s.size())
        {
            //find if it contains // or */
            string t;
            j=0;
            while(j<s[i].size())
            {
                if(j+1<s[i].size())
                {
                    if(!comment&&s[i][j]==block[0]&&s[i][j+1]==block[1])// */ now find */
                    {
                        comment=1;
                        prev=t;
                        j+=2;
                        continue;
                    }
                    else if(!comment&&s[i][j]==dbl[0]&&s[i][j+1]==dbl[1]) // //
                        break;
                    else if(comment&&s[i][j]==end[0]&&s[i][j+1]==end[1])// */ now find */
                    {
                        comment=0;
                        t=prev;
                        j+=2;
                        continue;
                    }
                }
                
                if(j<s[i].size()&&!comment)
                    t.push_back(s[i][j]);
                 j++;
            }
            i++;
            if(t.size()&&!comment)
            v.push_back(t);
        }
        
     return v;
    }
};