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
    
    ll a[100+100]={0};
    
    ll ans = 0;
    
    fr(i,n)
    {
    	ll x;
    	cin>>x;
    	a[x]++;
    	ans = max(ans, a[x]);
    }
    cout<<ans<<endl;
}
