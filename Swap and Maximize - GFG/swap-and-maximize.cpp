// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int a[], int n)
{
    sort(a,a+n);
    long long int sum=0,i=0,j=n-1;
    while(i<j)
    {
        sum+=(a[j]-a[i++]);
        sum+=(a[j--]-a[i]);
    }
    sum+=(a[i]-a[0]);
    return sum;
}