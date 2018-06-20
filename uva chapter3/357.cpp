
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{

	ll n;
	ll x[6] = {0,1, 5, 10, 25, 50};
	while(cin>>n)
	{
		ll a[6][n+1];

		for(int i=0; i<6; i++)
			a[i][0]  = 1;

		for(int i=1; i<=n; i++)
			a[0][i]  = 0;

		for(int i=1; i<6; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(j<x[i])
					a[i][j] = a[i-1][j];
				else
					a[i][j] = a[i-1][j]+a[i][j-x[i]];
				//cout<<a[i][j]<<" ";
			}
		//	cout<<endl;
//			
		}
		ll ans = a[5][n];
		if(ans!=1)
			cout<<"There are "<<ans<<" ways to produce "<<n<<" cents change."<<endl;
		else
			cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
	}
}
