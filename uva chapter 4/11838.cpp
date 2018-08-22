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

vector<int> v[2000+10], vr[2000+10];
bool visited[10+2000];
stack<int> s;


void initi(int n)
{
    fre(i,n)
    {
       v[i].clear();
       vr[i].clear();
      visited[i] = false;
    }
}

void initi1(int n)
{
    fre(i,n)
    {
       
      visited[i] = false;
    }
}
void dfs(int i)
{
  visited[i] = true;
  int size = v[i].size();

  fr(j,size)
  {
      if(!visited[v[i][j]])
        dfs(v[i][j]);
  }
  s.push(i);
}

int main()
{
    int n,m,x,y,z,size;
    while(cin>>n>>m)
    {

        if(n==0 && m==0)
            break;
      initi(n);
      while(m--)
      {
          cin>>x>>y>>z;
          v[x].pb(y);
          vr[y].pb(x);

          if(z==2)
          {
            vr[x].pb(y);
            v[y].pb(x);

          }
      }

      fre(i,n)
      {
          if(!visited[i])
            dfs(i);
      }
      initi1(n);
      ll ans = 0;
      while(!s.empty())
      {
        z = s.top();
        s.pop();
        if(visited[z])
            continue;

          
          ans++;
          stack<int> st;
          st.push(z);
          visited[z]=true;

            while(!st.empty())
            {
                z = st.top();
                st.pop();

                size = vr[z].size();
        
                fr(i,size)
                {
                    if(!visited[vr[z][i]])
                    {
                       // cout<<vr[z][i]<<" ";
                        visited[vr[z][i]] = true;
                        st.push(vr[z][i]);
                        
                    }
                }
            }
      }
      if(ans>1)
          ans=0;
      cout<<ans<<endl;
    }

}

