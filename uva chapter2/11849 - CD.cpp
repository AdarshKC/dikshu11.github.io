#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	ll n,m;
	while(1)
	{
		cin>>n>>m;
		if(n==0 && m==0)
			break;
		else
		{
			set<ll> s;
			ll x;
			for(ll  i=0; i<n+m; i++)
			{
				cin>>x;
				s.insert(x);
			}
			cout<<n+m-s.size()<<endl;
		}
	}
}
