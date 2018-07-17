#include<bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
#define pb push_back
#define mp(i,j) make_pair(i,j)
#define fi first
#define se second
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio (false) ; 
    cin.tie(0) ; cout.tie(0) ;
	
	ll n;
	cin>>n;
	ll a[n];
	
	fr(i,n)
	{
		cin>>a[i];
		if(a[i]%2==0)
			a[i] --;
	}
	fr(i,n)
		cout<<a[i]<<" ";
	
}
