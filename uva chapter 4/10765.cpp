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

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if(a.se> b.se)
        return true;
    if(a.se==b.se)
        return (a.fi<b.fi);
    return false;
}

void dfs(ll x, ll t, ll* parent, ll* low, ll* disc, bool* visited, ll* freq, vector<ll> v[])
{
    visited[x] = true;
    low[x] = disc[x] = t+1;
    ll child = 0;
    ll size = v[x].size();

    fr(i,size)
    {
        ll y = v[x][i];

        if(y==parent[x])
            continue;
        if(!visited[y])
        {
            parent[y] = x;
            child++;
            dfs(y,t+1, parent, low, disc, visited, freq, v);
            low[x] = min(low[x] , low[y] );

            if(parent[x]== -1 && child>=2)
                freq[x]++;
            else if(parent[x] != -1 && low[y]>=disc[x])
            {
                freq[x]++;
            }

        }
        else if(visited[y])
            low[x] = min(low[x] , low[y] );
    } 
}
 
int main()
{
   ll t,x,y,z,size,n,m;
   char c;
   while(cin>>n>>m )
   {
        if(n==0 && m==0)
            break;

        vector<ll> v[n+1];
        while(1)
        {
            cin>>x>>y;
            if(x==-1 && y==-1)
                break;
            v[x].pb(y);
            v[y].pb(x);
        }
        ll parent[n+1] , low[n+1], disc[n+1];
        bool visited[n+1];
        ll freq[n+1];

        fr(i,n)
        {
            parent[i] = -1;
            low[i] = 1e10;
            disc[i] = 0;
            visited[i] = false;
            freq[i] = 0;
        }
        ll num=0;
        fr(i,n)
        {
            if(!visited[i])
            {
                num++;
                dfs(i, 0, parent, low, disc, visited, freq, v );
            }
        }
        vector<pii> a;
        fr(i,n)
            a.pb(mp(i,freq[i]+num));

        sort(a.begin(), a.end(), sortbysec);

        fr(i,m)
            cout<<a[i].fi<<" "<<a[i].se<<endl;

        cout<<endl;
        

   }




}
