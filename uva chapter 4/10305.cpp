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


int main()
{
    
    ll n,m,x,y,z,size;
    while(cin>>n>>m)
    {
        if(m==0 && n==0)
            break;
        vector<ll> v[n+1];
        ll ind[n+1] = {0};
        fr(i,m)
        {
            cin>>x>>y;
            v[x].pb(y);
            ind[y]++;
        }

        queue<ll> q;
        fre(i,n)
        {
            //cout<<ind[i]<<" ";
            if(ind[i]==0)
                q.push(i);
        }
        vector<ll> ans;
        while(!q.empty())
        {
            z = q.front();
            q.pop();
            ans.pb(z);
            size = v[z].size();

            fr(i,size)
            {
                ind[v[z][i]]--;
                if(ind[v[z][i]] == 0)
                    q.push(v[z][i]);
            }
        }
        fr(i,ans.size())
        {
            cout<<ans[i];
            if(i==ans.size()-1)
                cout<<endl;
            else
                cout<<" ";
        }
        //cout<<endl;
    }



    
}
