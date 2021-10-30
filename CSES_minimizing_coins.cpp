/*
Input

The first input line has two integers n and x: the number of coins and the desired sum of money.

The second line has n distinct integers c1,c2,…,cn: the value of each coin.

Output

Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print −1.

Solution given is correct on all test cases

*/




#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
#define endl "\n"
#define precise(x,y)    fixed<<setprecision(y)<<x
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    PBDS;
typedef long long int ll;
const int N=1e5;
void solve(){
	ll n,x;
	cin>>n>>x;
	ll arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	ll dp[x+1]={0};
	for(ll i=0;i<=x;i++){
		dp[i]=LONG_MAX;
	}
	dp[0]=0;
	for(ll i=1;i<=x;i++){
		ll ans=LONG_MAX;
		for(ll j=0;j<n;j++){
 
			if(i-arr[j]>=0){
				ans=min(dp[i-arr[j]],ans);
			}
		}
		if(ans!=LONG_MAX)
		dp[i]=ans+1;
	}
	//for(int i=0;i<=x;i++)cout<<dp[i]<<endl;
	if(dp[x]==LONG_MAX)cout<<-1<<endl;
	else cout<<dp[x]<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
	int t=1;
	//cin>>t;
	while(t--){
	solve();
	}
	return 0;
}