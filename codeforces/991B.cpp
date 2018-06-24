#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() 
{
	ll n;
	cin>>n;
	double z =0;
	ll y[n];
	for(int i=0; i<n; i++)
	{
		cin>>y[i];
		z+=y[i];
		
	}
	double x = n;
	sort(y, y+n);
	ll ans =0;
	for(int i=0; i<n; i++)
	{
		if(z/x>=4.5)
			break;
		else
		{
			ans++;
			z+=5-y[i];
		}
	}
	cout<<ans<<endl;


}
