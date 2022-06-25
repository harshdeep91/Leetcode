//if we make a tree of steps then
![image](https://assets.leetcode.com/users/images/1f728238-8459-4a09-8065-44f4986917d4_1656155439.8047125.jpeg)
// here i have made a tree and you see
// if odd value come then it completely change the tree by including odd values and
//removing even values
//extra odd value added is size/2
//same for even but here prev values remain
//for any value to be find we need to check if it is odd or even
// then suppose 9 then we need last value to odd and greater or equal to 9
// on odd steps(1,3) value changes
// on even steps (2,4) value remain same
0
1  => 1/2+1 =>1
2  => 2/2     => 1
3 => 3/2+1  => 2
4 => 4/2       =>2