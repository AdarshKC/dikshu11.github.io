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

 vector<pii> ans;

void dfs(ll x, ll t, bool* visited, ll* parent, ll* low, ll* disc, vector<ll> v[])
{
    visited[x] = true;
    low[x] = disc[x] = t+1;
    //cout<<x<<" "<<t<<endl;
    ll size = v[x].size();
    fr(i,size)
    {
        ll a = v[x][i];
        if(a==parent[x])
                continue;
        if(visited[a])
            low[x] = min(low[x], low[a]);
        else
        {
            parent[a] = x;
            dfs(a,t+1, visited, parent, low, disc, v);

            low[x] = min(low[x] , low[a]);

            if(low[a]>disc[x])
            {
                //cout<<x<<" "<<a<<endl;
                if(a<x)
                    ans.pb(mp(a,x));
                else
                    ans.pb(mp(x,a));
            }    
        }

    }

}

int main()
{
   ll t,x,y,z,size;
   char c;
   while(cin>>t )
   {

        if(t==0)
        {
            cout<<"0 critical links"<<endl<<endl;
            continue;
        }
        vector<ll> v[t+1];

        fr(i,t)
        {
            cin>>x;
            cin>>c>>y>>c;

            fr(j,y)
            {
                cin>>z;

                v[z].pb(x);
                v[x].pb(z);
            }
        }

        //vector<pii> ans;
        bool visited[t+1];
        ll parent[t+1], low[t+1], disc[t+1];
        fr(i,t+1)
        {
            parent[i] = -1;
            low[i] = 10000000000000;
            disc[i] = 0;
            visited[i] = false;
        }
        fr(i,t)
        {
            if(!visited[i])
                dfs(i,0,visited, parent, low, disc, v);
        }
        
        sort(ans.begin(), ans.end());
        z = ans.size();
        cout<<z<<" critical links"<<endl;

        fr(i,z)
        {
            cout<<ans[i].fi<<" - "<<ans[i].se<<endl;
        }
        cout<<endl;
        ans.clear();

   }




}
