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

stack<int> st1;
vector<int> v[100000+100];
bool visited[100000+100];

void dfs(int i)
{
  visited[i] = true;
  int size = v[i].size();

  fr(j,size)
  {
      if(!visited[v[i][j]])
        dfs(v[i][j]);
  }
  st1.push(i);
}

int main()
{
    int n,m,x,y,z,size, tp = 0,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        
        fr(i,m)
        {
            cin>>x>>y;
            v[x].pb(y);
           
        }
        fre(i,n)
            visited[i] = false;
        fre(i,n)
        {
            if(!visited[i])
              dfs(i);
        }

        ll ans =  0;
        

        while(!st1.empty())
        {
            z = st1.top();
            st1.pop();

            if(visited[z])
            { 
              
              ans++;
              stack<ll> st;
              st.push(z);
              visited[z] = false;

              while(!st.empty())
              {
                  z = st.top();
                  st.pop();
                  size = v[z].size();

                  fr(i,size)
                  {
                      if(visited[v[z][i]])
                      {
                         visited[v[z][i] ] = false;
                         st.push(v[z][i]);
                      }
                  }
              }
              
            }
        }
        fre(i,n)
          v[i].clear();
        cout<<ans<<endl;
      
        
    }

}

