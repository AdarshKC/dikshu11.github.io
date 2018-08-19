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

set<ll> ans;
 
void dfs(ll x, ll t, bool* visited, ll* parent, ll* low, ll* disc, vector<ll> v[] )
{
    visited[x] = true;
    disc[x] = low[x] = t+1;

    ll size = v[x].size();
    ll child=0;
    fr(i,size)
    {
        ll y = v[x][i];
        if(y==parent[x])
            continue;
        if(visited[y])
            low[x] = min(low[x], disc[y]);
        else
        {
            child++;
            parent[y] = x;

            dfs(y,t+1, visited, parent, low,disc,v);

            low[x] = min(low[x], low[y]);
            if(parent[x]==-1 && child>1)
                ans.insert(x);
            else if(parent[x]!=-1 && low[y]>=disc[x])
                ans.insert(x);
        }
    }
}
int main()
{
       
    ll t, num=0;
    while(cin>>t && t)
    {
        if(num!=0)
            cout<<endl;
        num++;
        string s,s1;
        ll x,y,z,size;
        map<string, ll> ma;
        map<ll,string> ms;
        fr(i,t)
        {
            cin>>s;
            ma[s] = i;
            ms[i] = s;
        }
        ll n;
        cin>>n;
        vector<ll> v[t+1];
        fr(i,n)
        {
            cin>>s>>s1;
            x = ma[s];
            y = ma[s1];
            v[x].pb(y);
            v[y].pb(x);
        }
        bool visited[t+1];
        ll parent[t+1], low[t+1], disc[t+1];
        fr(i,t)
        {
            parent[i] = -1;
            low[i] = 100000000;
            visited[i] = false;
        }
        fr(i,t)
        {
            if(!visited[i])
                dfs(i,0,visited, parent, low,disc,v);
        }

        size = ans.size();
        vector<string> vans;
        cout<<"City map #"<<num<<": "<<size<<" camera(s) found"<<endl;
        for(auto pq: ans)
        {
            vans.pb(ms[pq]);
        }
        sort(vans.begin(), vans.end());
        for(auto g: vans)
            cout<<g<<endl;
        
        ans.clear();
    }



}
