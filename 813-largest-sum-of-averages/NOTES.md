//first method is to partition at every position
// 2^n because each postion has two choice we can reduce it n*n
// so average must be maximum this is goal
//k partition means k max arrays
// 9 1 2 3 9 => 10+14=> 24/3=> 8 this is lowest we can achieve
// 9 1 2 3 9
//1 2 3 4 5 6 7 => 28/4=> 7
// 1 5 2 6 3 7 4   => 1 5 2 ,63,7,4
// 5 5.5 7 => 17.5
// 1 2 3 4 =>5
// 5 6 =>5.5
// 7 => 7
//now we have to 1 extra value remove from lowest averages
//every value can has option to start new partition or continue from old
//max
//7/4=> 1, 3 extra