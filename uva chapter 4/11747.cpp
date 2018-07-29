#include<bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
#define pb push_back
#define piii pair<ll , pair<ll,ll> >
#define pii pair<ll,ll>
#define mp(i,j) make_pair(i,j)
#define fi first
#define ve vector
#define se second
using namespace std;
 
int main()
{
	ll n,m,x,y,z,size;
	while(cin>>n>>m )
	{
		if(n==0 && m==0)
			break;
		ve<pii> v[n+2];
		map<ll,ll> ma;
		fr(i,m)
		{
			cin>>x>>y>>z;
			v[x].pb( mp(z,y));
			v[y].pb( mp(z,x));
			ma[z]++;
			
		}
		bool visited[n+2] = {false};
		ve<ll> ans;
		priority_queue<pii, ve<pii> , greater<pii> > pq;
		fr(k,n)
		{
			if(!visited[k])
			{
				pq.push(mp(-1,k));
		

				while(!pq.empty() )
				{
					pii p = pq.top();
					pq.pop();
					x = p.se;
					if(visited[x]==true)
						continue;
					else
					{
						visited[x] = true;
						ma[p.fi]--;
						size = v[x].size();
						fr(i,size)
						{
							y = v[x][i].se;
							if(!visited[y])
								pq.push(v[x][i]);
							
						}
					}
				}
			}
		}
		map<ll,ll> :: iterator it;
		for(it = ma.begin(); it!= ma.end(); it++ )
		{
			
			ll z = it->se;
			fr(i,z)
				ans.pb(it->fi);
		}
		size = ans.size();
		if(size==0)
			cout<<"forest"<<endl;
		else
		{
			fr(i,size)
			{
				cout<<ans[i];
				if(i!=size-1)
					cout<<" ";
			}
			cout<<endl;
		}
	}

}
