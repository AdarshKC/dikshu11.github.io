#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
		ll n,t;
		cin>>t;
		while(t--)
		{
			cin>>n;
			ll a[n][n*2];
			ll max = -10000000;
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
						cin>>a[i][j];
					a[i][j+n]=a[i][j];
					if(a[i][j]>max)
						max = a[i][j];
					
				}
			}
			ll x[n*2];
			ll sum = max;
			for(ll i=0; i<n; i++)
			{
				ll o  = min(2*n, i+n);
					for(ll j=i; j<o; j++)
					{
						if(j==i)
						{
							for(ll k=0; k<n; k++)
							{	x[k] = a[k][j] ,x[k+n] = x[k];
								
							}	
						}
						else
						{
							for(ll k=0; k<n; k++)
							{	x[k] += a[k][j],x[k+n] = x[k];
							}
						}
						
						//ll start = 0;
						for(ll k=0; k<2*n; k++)
						{
							ll csum = 0;
							for(ll y = k; y<min(2*n,k+n) ; y++)
							{
								csum+=x[y];
								if(csum<0)
									csum = 0;
								if(csum>sum)
									sum =csum; 
							}
							
						}
					
					}	
				
			}
			if(max<0)
				cout<<max<<endl;
			else
				cout<<sum<<endl;
		}
		
}
