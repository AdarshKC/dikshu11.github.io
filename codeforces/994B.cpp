#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ll n,k;
	cin>>n>>k;

	ll a[n], c[n];
	
	vector<pair<ll,ll>  > v;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
	{
		cin>>c[i];
		v.push_back(make_pair(a[i], i) );
	}
	ll ans[n];
	
	priority_queue< ll, vector<ll>, greater<ll> > p;
	sort(v.begin(), v.end());

	ll sum = c[v[0].second ];
	p.push(sum);
	ans[ v[0].second] = c[v[0].second ];
	int flag = 0;
	if(k!=0)
	{
	for(int i=1; i<n; i++)
	{
		ll a = v[i].second;
		
		if(p.size()<k)
		{
			ans[ a] = c[a]+sum;
			sum+= c[a];
			p.push(c[a ]);
		//	cout<<v[i].first<<ans[v[i].second]<<endl;
		}
		else if(flag==0)
		{
			ans[ a] = c[a]+sum;
			flag=1;
		}
		else if(flag==1)
		{
			if(c[ v[i-1].second ] > p.top())
			{
				
				sum-=p.top();
				p.pop();
				p.push( c[v[i-1].second] );
				sum+= c[v[i-1].second];
				ans[ a] = c[a]+sum;
				//cout<<v[i].first<<" "<<sum<<" "<<ans[a]<<endl;
				
			}
			else
				ans[ a] = c[a]+sum;	
		}
		
		
	}

	for(int i=0; i<n; i++)
		cout<<ans[i]<<" ";
	}
	else
	{
		for(int i=0; i<n; i++)
		cout<<c[i]<<" ";	
	}


	
}
