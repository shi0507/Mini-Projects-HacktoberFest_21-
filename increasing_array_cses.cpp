#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	long long n;
	cin>>n;
	long long a[n];
	for(long long i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	
	long long c;
	c=0;
	for(long long i=1;i<n;i++)
	{
	    if(a[i]<a[i-1]) 
	    {
        //if previous element is greater than update the current value and store the number of difference between the current and previous element
	        c = c + (a[i - 1] - a[i]);
	        a[i] = a[i - 1];
	        
	    }
	}
 
	  
 
	cout<<c<<" ";
	return 0;
}
