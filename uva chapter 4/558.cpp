#include<bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
#define pb push_back
#define mp(i,j) make_pair(i,j)
#define fi first
#define se second
#define pii pair<ll,ll>
#define piii pair<ll,pii>
using namespace std;

ll inf = 1e18;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,x,y,z,size;
        cin>>n>>m;

        ll dist[n+1] = {inf};
        vector<pii> v[n+1];

        fr(i,m)
        {
            cin>>x>>y>>z;
            v[x].pb(mp(y,z));
            //v[y].pb(mp(x,z));
        }
        dist[0] = 0;

        fr(i,n)
        {
            int j=0;
            while(j<n)
            {
                size = v[j].size();
                fr(k,size)
                {
                   dist[v[j][k].fi] = min(dist[v[j][k].fi], dist[j]+v[j][k].se);
                }
                j++;
            }
        }

            int j=0, flag = 0;
            while(j<n)
            {
                size = v[j].size();
                fr(k,size)
                {
                   x = min(dist[v[j][k].fi], dist[j]+v[j][k].se);
                   if(x!= dist[v[j][k].fi] && dist[v[j][k].fi]!=inf )
                        flag=1;

                }
                j++;
            }

            string ans = "not possible\n";
            if(flag)
                ans="possible\n";
            cout<<ans;


    }



    
}
