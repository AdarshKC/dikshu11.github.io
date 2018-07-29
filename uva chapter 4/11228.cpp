#include<bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
#define pb push_back
#define piii pair<double , pair<ll,ll> >
#define pii pair<ll,ll>
#define mp(i,j) make_pair(i,j)
#define fi first
#define ve vector
#define se second
using namespace std;
 
int main()
{
	ll t,n,r,x,y,z,size,num=0;
	cin>>t;
	while(t--)
	{
		num++;
		cout<<"Case #"<<num<<": ";
		cin>>n>>r;
		vector<pii> v;
		fr(i,n)
		{
			cin>>x>>y;
			v.pb(mp(x,y));
		}
		priority_queue< piii, vector<piii>, greater<piii> > pq;		
		map<pii, ll> ma;
		map<pii, ll>:: iterator it;
		pq.push(mp(0,v[0] ));
		double road=0, state=1, rail = 0;
		while(!pq.empty())
		{
			piii pi = pq.top();
			pq.pop();
 			pii p = pi.se;

 			it = ma.find(p);
 			if(it==ma.end())
 			{
 				ma[p] = 1;
 				//cout<<pi.fi<<endl;
 				if(pi.fi<=r)
 					road += pi.fi;
 				else
 					state++, rail+= pi.fi;

 				fr(i,n)
 				{
 					it = ma.find(v[i]);
 					if(it==ma.end())
 					{
 						double dist = sqrt((v[i].fi-p.fi)*(v[i].fi-p.fi) + (v[i].se-p.se)*(v[i].se-p.se));
 						pq.push(mp(dist, v[i]));
 					}
 				}
 			}
		}
		road = round(road);
		rail = round(rail);
		cout<<state<<" "<<road<<" "<<rail<<endl;
	}
}
