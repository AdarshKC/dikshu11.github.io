#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() 
{
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	ll ans;
	ll time = 10000000000;
	for(int i=0; i<n; i++)
	{
		double x = a[i]-i;
		x/=n;
		ll z = ceil(x);
		if(z<time)
			time = z, ans = i;
	}

	cout<<ans+1<<endl;
}
