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
    string s;
    getline(cin, s);
    while(t--)
    {

        vector<ll> v[260];
        ll  a[270]={0}, ind[270], dist[270];
        bool visited[27];

        fr(i, 26)
        {
           ind[i] = 0;
           dist[i] = -10000;
           visited[i] = false;
        }
        
        char c;
        ll x,y,z,size;
        cin>>c>>y;
        a[c-'A'] =y;
        getline(cin, s);
        while(getline(cin, s))
        {
            if(s.length()==0)
                break;

            x = s[0]-'A';
            bool flag = false;
            for(int j=2; j<s.length(); j++)
            {
                if(s[j] ==' ')
                {
                    ll num = 0;
                    ll in = 1;

                    int h = j-1;

                    while(h>=2)
                    {
                        int g = s[h]-'0';

                        num+=g*in;
                        h--;
                        in*=10;
                    }
                    flag = true;
                    a[x] = num;
                    //cout<<a[x]<<" ";
                }
                else if(flag==true)
                {
                    y = s[j]-'A';
                    v[y].pb(x);
                }
            }
            if(flag==false)
            {
                int h = s.length()-1;
                ll num = 0;
                    ll in = 1;

                    while(h>=2)
                    {
                        int g = s[h]-'0';

                        num+=g*in;
                        h--;
                        in*=10;
                    }
                    flag = true;
                    a[x] = num;
            } 


        }
        queue<ll> q;
        vector<ll> v1;
        fr(i,26)
        {
            if(ind[i]==0)
            {
                v1.pb(i);
                dist[i] = a[i];
                visited[i] = true;
                q.push(i);
            }
        }

        while(!q.empty())
        {
            z = q.front();
            q.pop();

            size = v[z].size();
            fr(i, size)
            {
                ind[v[z][i]]--;
                if(ind[v[z][i]]==0 && visited[v[z][i]]==false)
                {
                    visited[v[z][i]] = true;
                    q.push(v[z][i]);
                    v1.pb(v[z][i]);
                }
            }
        }
        fr(k,v1.size())
        {
            
            x = v1[k];
            size = v[x].size();
            fr(i, size)
            {
                y = v[x][i];
                dist[y] = max(dist[y], dist[x]+a[y]);
            }
        }
        ll ans = -1;
        fr(i,26)
        {
           // cout<<dist[i]<<" "<<a[i]<<endl;
            ans = max(ans, dist[i]);
        }
        cout<<ans<<endl;
        if(t!=0)
            cout<<endl;
    }
      

}
