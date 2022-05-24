class Solution {
public:
    
    vector<vector<long long int >> dp;
    
    long long int getint( vector<int> & maxa ){
        long long int result = 0;
        for( int i = 1 ; i < maxa.size() ; i++ ){
            result = (result<<1) + maxa[i];
        }

        return result;
    }
    
    
    int dfs( int player , vector<int>& maxa , int total ){
        if( total <= 0 ){
            if( player == 1 ){
                return 1;
            }else{
                return 0;
            }
        }
        
        bool ret = player ;
        
        for( int i = 1 ; i < maxa.size() ; i++ ){
            
            if( maxa[i] == 1 ){
                maxa[i] = 0;
                long long int j = getint(maxa);
                if( player == 0 ){
                    if( dp[1][j] == -1 ){
                        dp[1][j] =  dfs( 1 , maxa , total-i ) ;
                    }
                    ret = (ret || dp[1][j]);
                    if( ret == 1 ){
                        maxa[i] = 1;
                        return 1;
                    }
                    
                }else{
                    
                    if( dp[0][j] == -1 ){
                        dp[0][j] =  dfs( 0 , maxa , total-i ) ;
                    }
                    ret = ( ret && dp[0][j] );
                    if( ret == 0 ){
                        maxa[i] = 1;
                        return 0;
                    }
                }  
                maxa[i] = 1;         
            }
        }
        return ret;   
    }
    
    bool canIWin(int n, int desiredTotal) {
        // Base conditions
        if( desiredTotal == 0 ){
            return true;
        }else if( n*(n+1)/2 < desiredTotal) {
            return false;
        }
        
        vector<int> maxa(n+1,1);
        dp.resize( 2, vector< long long int >( pow(2,n)+1 ,-1 ) );
        

        return dfs( 0 , maxa , desiredTotal ) ;
             
        
        
        
        
    }
};