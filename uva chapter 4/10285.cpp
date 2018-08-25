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


bool isvalid(ll x, ll y, ll n, ll m)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    return true;
} 
int main()
{

    ll t;
    cin>>t;
    while(t--)
    {
         ll dx[4] = {-1, 1, 0,0};
          ll dy[4] = {0,0, 1, -1};
          string s;
        ll n,m,t,x,y,x1,y2;
        cin>>s>>n>>m;
       
        ll a[n][m];
        ll ind[n][m];
        ll dist[n][m];
        bool visited[n][m];

        fr(i,n)
          fr(j,m)
          {
            dist[i][j] = -1e14;
            ind[i][j] = 0;
            visited[i][j] = false;
            cin>>a[i][j];
          }

        fr(i,n)
        {
           fr(j,m)
           {
              fr(k,4)
              {
                  x = i+dx[k], y = j+dy[k];

                  if(isvalid(x,y,n,m)&& a[x][y]<a[i][j])
                    ind[x][y]++;
              }
           }
        }

        queue<pii> pq;

        vector<pii> v;
        fr(i,n)
          fr(j,m)
          {
             if(ind[i][j]==0)
             {
                pq.push(mp(i,j));
                visited[i][j] = true;
                dist[i][j] = 1;
                v.pb(mp(i,j));
             }
          }

        while(!pq.empty())
        {
           
            pii p = pq.front();
            
            pq.pop();

            fr(i,4)
            {
              x = p.fi+dx[i] , y = p.se+ dy[i];
              if(isvalid(x,y,n,m) && a[x][y]<a[p.fi][p.se] && visited[x][y]==false)
              {
                  ind[x][y]--;
                  if(ind[x][y] == 0)
                  {
                      pq.push(mp(x,y));
                      visited[x][y] = true;
                      v.pb(mp(x,y));
                  }
              }
            }
        }
        ll size = v.size();
        ll ans = -100;
        fr(i,size)
        {
            x1 = v[i].fi;
            y2 = v[i].se;

            fr(i,4)
            {
               x = x1+dx[i] , y = y2+dy[i];
              if(isvalid(x,y,n,m) && a[x][y]<a[x1][y2] )
              {
                 dist[x][y] = max(dist[x][y], dist[x1][y2]+1);
              }
            }
        }

        fr(i,n)
          fr(j,m)
            ans = max(ans,dist[i][j]);

        cout<<s<<": "<<ans<<endl;


    }
      

}
