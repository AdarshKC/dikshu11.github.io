#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
		ll n,t,m,K;
		cin>>t;
		ll num = 1;
		while(t--)
		{
			cin>>n>>m>>K;
			ll a[n][m];
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<m; j++)
					cin>>a[i][j];
			}

			ll area = 0;
			ll x[n];
			ll cost = 0;
			for(int i=0; i<m; i++)
			{
				for(int j=i; j<m; j++)
				{
					if(i==j)
					{
						for(ll k=0; k<n; k++)
							x[k] = a[k][j];
					}
					else
					{
						for(ll k=0; k<n; k++)
							x[k] += a[k][j];
					}
					for(ll k=0; k<n; k++)
					{
						ll start = k;
						ll end = k;
						ll csum = 0;
						while(end <n)
						{
							csum+=x[end];
							if(csum>K)
								break;
							if( (j-i+1)*(end-start+1)>area && csum<=K)
							{
								area = (j-i+1)*(end-start+1);
								cost = csum;
							}
							else if((j-i+1)*(end-start+1)==area && csum<=K)
							{
								cost = min(cost, csum);
							}
							end++;
						}
					//	cout<<i<<" "<<j<<" "<<start<<" "<<end<<" "<<area<<endl;
						
					}
				}
			}
			cout<<"Case #"<<num<<": "<<area<<" "<<cost<<endl;
			num++;
		}

				
}
