#include<bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
#define pb push_back
#define mp(i,j) make_pair(i,j)
#define fi first
#define se second
using namespace std;
 
ll num(ll x)
{
	if(x==1)
		return 2;
	return 1;
}
int main()
{
    ios_base::sync_with_stdio (false) ; 
    cin.tie(0) ; cout.tie(0) ;

	ll t,n,m,x,y,z,size;
	
	while(cin>>n && n)
	{
		cin>>m;
		vector<ll> v[n];
		fr(i,m)
		{
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
		}

		ll ans[n] = {0};
		bool is = true;
		bool visited[n] = {false};
		queue<ll> q;
		q.push(0);
		visited[0] = true;
		ans[0] = 1;
		while(!q.empty())
		{
			z = q.front();
			q.pop();

			size = v[z].size();
			fr(i,size)
			{
				if(!visited[v[z][i]])
				{
					visited[v[z][i]] = true;
					ans[v[z][i]] = num(ans[z]);
					q.push(v[z][i]);
				}
				else if(ans[z] == ans[v[z][i]])
				{
					is = false;
					break;
				}
			}
			if(!is)
				break;
		}

		string answ = "NOT BICOLORABLE.";
		if(is)
			answ = "BICOLORABLE.";

		cout<<answ<<endl;
	}
}
