#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ll t;
	cin>>t;
	ll num=1;
	while(num<=t)
	{
		ll n;
		cin>>n;
		ll l[n] , w[n];
		for(ll i=0; i<n; i++)
			cin>>l[i];
		for(ll i=0; i<n; i++)
			cin>>w[i];

		ll weighti[n]; 
		ll leni[n];
		ll maxwi = w[0];

		ll weightd[n]; 
		ll lend[n];
		ll maxwd = w[0];

		for(int i=0; i<n; i++)
		{
			weighti[i] = w[i];
			weightd[i] = w[i];
		}
		

		for(ll i=1; i<n; i++)
		{
			for(ll j=0; j<i; j++)
			{
				if( l[j] < l[i] )
				{
					if(weighti[j]+ w[i] > weighti[i])
						weighti[i] = weighti[j]+ w[i];
				}
			}

			if(weighti[i]>maxwi)
				maxwi = weighti[i];



			for(ll j=0; j<i; j++)
			{
				if( l[j] > l[i] )
				{
					if( weightd[j]+ w[i] > weightd[i])
						weightd[i] = weightd[j]+ w[i];
				}
			}

			if(weightd[i]>maxwd)
				maxwd = weightd[i];
		}
		if(maxwi>=maxwd)
			cout<<"Case "<<num<<". Increasing ("<<maxwi<<"). Decreasing ("<<maxwd<<")."<<endl;
		else
			cout<<"Case "<<num<<". Decreasing ("<<maxwd<<"). Increasing ("<<maxwi<<")."<<endl;
		num++;
	}

}
