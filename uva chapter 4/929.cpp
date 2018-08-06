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

bool isvalid(ll x, ll y, ll n, ll m)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio (false) ; 
    cin.tie(0) ; cout.tie(0) ;
    
    ll n,t,m,x,y,z,x1,y1,size;

    cin>>t;
    while(t--)
    {
        cin>>n>>m;

        ll a[n][m];
        ll dist[n][m];
        ll visited[n][m];

        fr(i,n)
            fr(j,m)
        {
            cin>>a[i][j];
            dist[i][j] = inf;
            visited[i][j] = false;
        }

        dist[0][0] = a[0][0];

        ll dx[4] = {-1,1,0,0};
        ll dy[4] = {0,0,-1,1};

        priority_queue< piii, ve<piii>, greater<piii>> pq;
        pq.push(mp(a[0][0],mp(0,0)));

        while(!pq.empty())
        {
            piii p = pq.top();
            pq.pop();
            x = p.se.fi;
            y = p.se.se;

            if(visited[x][y])
                continue;
            visited[x][y] = true;

            fr(i,4)
            {
                x1 = x+dx[i] , y1 = y+ dy[i];

                if(isvalid(x1,y1,n,m) && dist[x1][y1] > dist[x][y] + a[x1][y1])
                {
                    dist[x1][y1] = dist[x][y] + a[x1][y1];
                    pq.push(mp(dist[x1][y1] , mp(x1,y1)));
                }

            }
        }
        cout<<dist[n-1][m-1]<<endl;



    }

           
}
