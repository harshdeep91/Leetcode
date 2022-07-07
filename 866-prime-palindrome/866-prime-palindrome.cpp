class Solution {
public:
    int primePalindrome(int N) {
        while (true) {

            string val = to_string(N);
            bool flag=0;
            if (N > 11 && val.size() % 2 == 0) {
                N = pow(10, val.size());
                flag=1;
            }
            // cout<<N<<" "<<val<<endl;
            if (N == reversed(N) && isPrime(N))
                return N;
            val=to_string(N);
            int k = val.size() / 2;
            int c = val[k] - '0';
            if (flag||c == 9 || N <= 11) {
                N++;
                flag=0;
            } else {
                val=val.substr(0,k);
                string back=val;
                reverse(back.begin(),back.end());
                val.push_back(c + 1+'0');
                val+=back;
                N = stoi(val);
            }
        }
    }

    bool isPrime(int N) {
        if (N < 2) return false;
        int Nsqrt = (int) sqrt(N);
        for (int i = 2; i <= Nsqrt; ++i)
            if (N % i == 0) return false;
        return true;
    }
     int reversed(int N) {
        int reversedVal = 0;
        while (N > 0) {
            reversedVal = 10 * reversedVal + (N % 10);
            N /= 10;
        }
        return reversedVal;
    }

};