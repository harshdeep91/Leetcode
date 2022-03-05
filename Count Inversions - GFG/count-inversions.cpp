// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long * temp,count,i,j,k;
    void merge(long long arr[],long long l,long long m,long long h)
    {
          i=l;
          j=m+1;
          k=l;
          while(i<=m&&j<=h)
          {
              if(arr[i]<=arr[j])
              temp[k++]=arr[i++];
              else
              {
                  temp[k++]=arr[j++];
                  count+= m-i+1;
              }
          }
          while(i<=m)
          {
            //   count++;
              temp[k++]=arr[i++];
          }
          while(j<=h)
          temp[k++]=arr[j++];
          while(l<k)
              arr[l]=temp[l++];
    }
    void mergesort(long long arr[],long long l,long long h)
    {
        if(l<h)
        {
            long long m=l+(h-l)/2;
            mergesort(arr,l,m);
            mergesort(arr,m+1,h);
            merge(arr,l,m,h);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        count=0;
       temp=new long long[N];
       mergesort(arr,0,N-1);
    //   for(long long c=0;c<N;c++)
    //   cout<<arr[c]<<" ";
    //   cout<<endl;
       return count;
    }

};
// 42
// 468 335 1 170 225 479 359 463 465 206 146 282 328 462 492 496 443 328 437 392 105 403 154 293 383 422 217 219 396 448 227 272 39 370 413 168 300 36 395 204 312 323

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends