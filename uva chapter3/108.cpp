#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
		ll n;
		cin>>n;
		ll a[n][n];
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				cin>>a[i][j];
		}
		ll x[n];
		ll sum = -1000000000;
		for(ll i=0; i<n; i++)
		{
			for(ll j=i; j<n; j++)
			{
				if(j==i)
				{
					for(ll k=0; k<n; k++)
						x[k] = a[k][j];
				}
				else
				{
					for(ll k=0; k<n; k++)
						x[k] += a[k][j];
				}
				ll csum = 0;
				ll msum = -10000000;
				for(ll k=0; k<n; k++)
				{
					csum+=x[k];
					if(csum<0)
						csum = 0;
					if(csum>msum)
						 msum =csum ;
				}
				if(msum>sum)
					sum = msum;
			}
		}
		cout<<sum<<endl;
}
