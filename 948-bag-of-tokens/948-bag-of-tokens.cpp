class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //we can achive this by sorting the powers and 
        //getting score first from small element and then gaining
        //maximum score from last element
        int score=0,i=0,j=tokens.size()-1,mx=0;
        sort(tokens.begin(),tokens.end());
        while(i<=j)
        {
            if(power>=tokens[i])//face down
                score++,power-=tokens[i++];
            else //get the power by last element
            {
                if(score>0)
                    score--,power+=tokens[j--];
                else 
                    return score;
            }
            mx=max(score,mx);
        }
        return mx;
    }
};