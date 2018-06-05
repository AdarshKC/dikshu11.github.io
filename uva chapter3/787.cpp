#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ll x;
	while(cin>>x)
	{
		vector<ll> v;
		v.push_back(x);
		while(cin>>x && x!=-999999)
		{
			v.push_back(x);
		}
		ll ans = -9999999;
		ll n = v.size();
		ll m[n][n];
		for(ll i=0; i<n; i++)
		{
			m[i][i] = v[i];
			if(m[i][i]>ans)
					ans = m[i][i];
		}

		for(ll L = 2; L<=n; L++)
		{
			for(ll i=0; i<n-L+1; i++)
			{
				ll j = i+L-1;
				m[i][j] = m[i][j-1]*v[j];
				if(m[i][j]>ans)
					ans = m[i][j];
			}
		}
		cout<<ans<<endl;

	}	


	
}
