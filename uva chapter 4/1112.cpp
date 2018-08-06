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
    
    ll n,t,m,e,x,y,z,x1,y1,size,ans,ti;

    cin>>t;
    while(t--)
    {
        cin>>n>>e>>ti;
        cin>>m;
        ans = 0;
        vector<pii> v[n+1];

        fr(i,m)
        {
            cin>>x>>y>>z;
            v[x].pb(mp(y,z));
        }
        
        fre(i,n)
        {
            bool visited[n+1] = {false};
            ll dist[n+1];

            fre(i,n)
                dist[i] = inf;

            dist[i] = 0;
             priority_queue< pii, ve<pii>, greater<pii>> pq;
                pq.push(mp(0,i) );

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
                //cout<<i<<" "<<dist[e]<<endl;;

                if(dist[e]<=ti)
                {

                    ans++;
                }    

        }
        cout<<ans<<endl;
        if(t!=0)
            cout<<endl;
       

       
        



    }

           
}
