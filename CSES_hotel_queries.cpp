/*
There are n hotels on a street. For each hotel you know the number of free rooms. Your task is to assign hotel rooms for groups of tourists. All members of a group want to stay in the same hotel.

The groups will come to you one after another, and you know for each group the number of rooms it requires. You always assign a group to the first hotel having enough rooms. After this, the number of free rooms in the hotel decreases.

Input

The first input line contains two integers n and m: the number of hotels and the number of groups. The hotels are numbered 1,2,…,n.

The next line contains n integers h1,h2,…,hn: the number of free rooms in each hotel.

The last line contains m integers r1,r2,…,rm: the number of rooms each group requires.

Output

Print the assigned hotel for each group. If a group cannot be assigned a hotel, print 0 instead.



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
void Sieve(bool *prime,int n)
{   
  prime[0]=false;
  prime[1]=false;
    for (int p = 2; p * p <= n; p++)
    {
         if (prime[p] == true) 
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
void buildStree(int*st,int*arr,int v,int l,int r){
	if(l==r){
			if(arr[l]<)
		st[v]=arr[l];return;}
	int mid=(l+r)/2;
	buildStree(st,arr,2*v,l,mid);
	buildStree(st,arr,2*v+1,mid+1,r);
	st[v]=max(st[2*v],st[2*v+1]);
}
int query(int*st,int v,int tl,int tr,int l,int r){
	if(l>r)return INT_MIN; 
	if(tl==l&&tr==r){
		return st[v];
	}
	int mid=(tl+tr)/2;
	return max(query(st,2*v,tl,mid,l,min(mid,r)),query(st,2*v+1,mid+1,tr,max(mid+1,l),r));
}
int mysearch(int x,int l ,int r,int*arr,int*st,int n){
	if(l>r)return -1;
	if(l==r){
		if(arr[l]>=x)return l;
		else return -1;
	}
	int mid=(l+r)/2;
	if(query(st,1,0,n-1,l,mid)>=x)return mysearch(x,l,mid,arr,st,n);
	else return mysearch(x,mid+1,r,arr,st,n);
}
void update(int*st,int v,int tl,int tr,int pos,int val){
	if(tl>tr)return;
	if(tl==tr){st[v]=val;return;}
	int mid=(tl+tr)/2;
	if(pos<=mid){
		update(st,v*2,tl,mid,pos,val);
	}
	else update(st,v*2+1,mid+1,tr,pos,val);
	st[v]=max(st[2*v],st[2*v+1]);
}
void solve(){
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
		int st[4*n];
	buildStree(st,arr,1,0,n-1);

	for(int i=0;i<m;i++){
		
		int x;
		cin>>x;
		int pos=mysearch(x,0,n-1,arr,st,n);
		cout<<pos+1<<endl;

		if(pos!=-1){arr[pos]=arr[pos]-x;
		update(st,1,0,n-1,pos,arr[pos]);}
		
	}
	

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt","r",stdin);
// 	freopen("output1.txt","w",stdout);
// #endif
	int t=1;
	//cin>>t;
	while(t--){
	solve();
	}
	return 0;
}
