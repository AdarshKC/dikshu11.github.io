#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ll n,m;
	cin>>n>>m;
	ll a[n];

	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}

	set<ll> s;
	for(int i=0; i<m; i++)
	{
		ll x;
		cin>>x;
		s.insert(x);
	}

	for(int i=0; i<n; i++)
	{
		if(s.find(a[i])!= s.end())
			cout<<a[i]<<" ";
	}
	//cout<<endl;
}
