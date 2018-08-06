#include<bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
#define pb push_back
#define mp(i,j) make_pair(i,j)
#define fi first
#define se second
#define ve vector
#define pii pair<ll,ll>
#define piii pair<ll, pii>
using namespace std;
 
ll inf = 1e12;


int main()
{
    ios_base::sync_with_stdio (false) ; 
    cin.tie(0) ; cout.tie(0) ;
    
    ll n,t,m,e,x,y,z,x1,y1,size,ans,ti,s,num = 0;

    cin>>t;
    while(t--)
    {
        cin>>n>>m>>s>>ti;
        num++;
        vector<pii> v[n+1];
        fre(i,m)
        {
            cin>>x>>y>>z;
            v[x].pb(mp(y,z));
            v[y].pb(mp(x,z));
        }
            bool visited[n+1] = {false};
            ll dist[n+1];

            fre(i,n)
                dist[i] = inf;

            dist[s] = 0;
             priority_queue< pii, ve<pii>, greater<pii>> pq;
                pq.push(mp(0,s) );

                while(!pq.empty())
                {
                    pii p = pq.top();
                    pq.pop();
                    x = p.se;

                    if(visited[x])
                        continue;
                    visited[x] = true;
                    size = v[x].size();

                    fr(j,size)
                    {
                        y = v[x][j].fi;

                        if(dist[y] > dist[x] + v[x][j].se)
                        {
                            dist[y] = dist[x] + v[x][j].se;
                            pq.push(mp(dist[y] ,y) );
                        }

                    }
                }
                cout<<"Case #"<<num<<": ";

                if(dist[ti]==inf)
                        cout<<"unreachable"<<endl;
                else
                    cout<<dist[ti]<<endl;

        
        
       

       
        



    }

           
}
