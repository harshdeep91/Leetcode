class Solution {
public:
    string solveEquation(string e) {
        //add int and x both sides
        //then subtract int from rhs lhs
        //then subtract int from lhr rhs
        //if x not found return infinitre
        //cou
        int count_int=0,count_x=0,i=0,rhs=0;
        while(i<e.size())
        {
            //count x
            int count=0,neg=1,updated=0;
            if(e[i]=='=')rhs=1,i++;
            if(e[i]=='-'||e[i]=='+')
                neg=e[i++]=='-'?-1:1;
             
            
            while(i<e.size()&&e[i]>='0'&&e[i]<='9')
            {
                count*=10,count+=e[i++]-'0';
                updated=1;
            }
              count*=neg;
            //now find int or x
            
            if(i<e.size()&&e[i]=='x')
            {
                count=count==0&&!updated?neg:count;
                count_x= rhs?count_x-count:count_x+count,i++;
            }
            else
                count_int= rhs?count_int+count:count_int-count;
            // cout<<count_int<<" "<<count_x<<endl;
        }
        if(count_x==0)
            return count_int==0?"Infinite solutions":"No solution";
        //if x is negitive we want it to be positive
        
        if(count_x<0)
        {
            count_x=-count_x;
            count_int=-count_int;
        }
        int t=gcd(count_x,count_int);
        count_x/=t;
        count_int/=t;
        string x=(count_x==1)?"x":to_string(count_x)+"x";
        return x+"="+to_string(count_int);
    }
};