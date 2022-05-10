class Solution {
public:
//     void solve(int &i,string &input,int t,int &mx,int ans)
//     {
//         int countt=0;
//         while(i+1<input.size()&&input[i]=='\\'&&input[i+1]=='t')
//         {
//             i+=2;
//             countt++;
//         }
//         if(t+1==countt)//means next child need to go
//         {
//             int count=0,i=0;
//              while(i<input.size()&&input[i]!='\\')
//             {
//                 i++;
//                 count++;
//             }
//             if(i==input.size())
//                 mx=max(ans+count,mx);
//             else
//             solve(i+2,input,0,mx,ans+count+1);
//         }
//         else if(t==countt)//sibling
//         {
            
//         }
//     }
     pair<int,int> length(int &i,string input)
    {
        int count=0,flag=0;
        while(i<input.size()&&input[i]!='*')
        {
            // cout<<input[i]<<" ";
            if(input[i]=='.')
                flag=1;
            i++;
            count++;
        }
         pair<int,int> p={flag,count};
         return p;
        
    }
    int lengthLongestPath(string input) {
        // cout<<input<<endl;
        for(int j=0;j<input.size();j++)
            if(input[j]=='\n')
                input[j]='*';
          else if(input[j]=='\t')
                input[j]='#';
        // cout<<input<<endl;
        stack<pair<int,pair<int,int>>> s;
         int i=0,mx=0;
        pair<int,int> p=length(i,input);
          s.push({0,p});
          while(i<input.size())
          {
              
                  i++;
              // cout<<i<<" "<<input[i]<<" "<<mx<<endl;
                  int countt=0;
                  while(i<input.size()&&input[i]=='#')
                    {
                        i++;
                        countt++;
                    }
                      if(countt==0)
                      {
                           pair<int,int> p=length(i,input);
                            s.push({0,p});
                          continue;
                      }
                      while(s.top().first+1>countt)
                      {
                          if(s.top().second.first)
                          mx=max(mx,s.top().second.second);
                          s.pop();
                      } 
                 pair<int,int> p=length(i,input);
                s.push({countt,{p.first||s.top().second.first,1+p.second+s.top().second.second}});
          }
                 while(!s.empty())
                      {
                            if(s.top().second.first)
                          mx=max(mx,s.top().second.second);
                          s.pop();
                      } 
        return mx;
    }
};