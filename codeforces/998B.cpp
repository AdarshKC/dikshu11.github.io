#include<bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio (false) ; 
    cin.tie(0) ; cout.tie(0) ;
    
    ll n, b;
    cin>>n>>b;
    
    ll a[n+1];
    ll sum[n+1];
    sum[0] = 0;
    fre(i,n)
    {
    	cin>>a[i];
    	if(a[i]%2)
    		sum[i] = sum[i-1]+1;
    	else
    		sum[i] = sum[i-1]-1;
    	
    //	cout<<sum[i]<<endl;
    	
    }
    vector<ll> v;
    ll prev = 0;
    fre(i,n-1)
    {
    	if(sum[i]==0)
    	{
    		//cout<<i<<endl;
    		v.push_back( abs(a[i+1] - a[i] ) );	
    		//cout<<abs(a[i+1] - a[i] )<<endl;
    	}
    }
    sort(v.begin(),v.end());
    ll ans =0;
    ll i = 0;
    ll s = b;
    
    while(i<v.size())
    {
    	if(v[i]<=s)
    	{
    		ans++;
    		s-=v[i];
    	}
    	i++;
    }
    cout<<ans<<endl;
    
}
