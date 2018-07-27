#include<bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
#define pb push_back
#define pii pair<ll,ll>
#define mp(i,j) make_pair(i,j)
#define fi first
#define se second
using namespace std;
 
int main()
{
	ll n,m,x,y,z;
	while(cin>>m>>n && n && m)
	{
		ll total = 0;
		vector<pii> v[m+100];
		fr(i,n)
		{
			cin>>x>>y>>z;
			v[x].pb(mp(z,y));
			v[y].pb(mp(z,x));
			total+=z;
		}

		ll cost = 0;
		bool visited[m+10000] = {false};
		priority_queue<pii, vector<pii>, greater<pii> > q;
		q.push(mp(0,0));

		while(!q.empty())
		{
			pii p = q.top();
			q.pop();
			x = p.second;

			if(visited[x]== false)
			{
				cost += p.first;
				//cout<<x<<" "<<p.first<<endl;
				visited[x] = true;
				ll size = v[x].size();
				fr(i,size)
				{
					y = v[x][i].second;
					if(!visited[y])
					{
						q.push( v[x][i] );
					}
				}
			}
		}
		cout<<total-cost<<endl;
	}

}

