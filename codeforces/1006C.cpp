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
	
	ll n,sum=0;
	cin>>n;
	ll a[n+1];
	
	map<ll,ll> m;
	map<ll,ll>:: iterator it;
	fre(i,n)
	{
		cin>>a[i];
		sum+= a[i];
		m[sum] = i;
	}
	
	sum = 0;
	ll ans = 0;
	for(int i=n; i>0; i--)
	{
		sum+= a[i];
		it = m.find(sum);
		if(it!=m.end())
		{
			if(i>m[sum])
				ans = max(sum,ans);
		}
	}
	cout<<ans;
}
