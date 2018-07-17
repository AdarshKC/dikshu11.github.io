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
	
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll> > v;
    ll a[n];
    fr(i,n)
    {
    	cin>>a[i];
    	v.pb(mp(a[i] , i) );
    }
    sort(v.begin() , v.end());
    reverse(v.begin() , v.end());
    bool visited[n] = {false};
    ll ans = 0;
    fr(i,k)
    {
    	visited[ v[i].se ] = true;
    	ans += v[i].first;
    }
    ll num=0, que=0;
    ll ind=0;
    cout<<ans<<endl;
    fr(i,n)
    {
	if(num==k-1)
	{
		ind = i;
		break;
	}
	if(visited[i] == true)
	{
		que++;
		cout<<que<<" ";
		que=0;
		num++;
	}
	else
	{
		que++;
	}
    }
    cout<<n-ind<<endl;
}

