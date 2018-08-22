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


bool visited[10+2000];
stack<int> st1;


void initi(int n)
{
    fre(i,n)
    {       
      visited[i] = false;
    }
}
void dfs(int i, vector<int> v[])
{
  visited[i] = true;
  int size = v[i].size();

  fr(j,size)
  {
      if(!visited[v[i][j]])
        dfs(v[i][j], v);
  }
  st1.push(i);
}

int main()
{
    int n,m,x,y,z,size;
    while(cin>>n>>m)
    {
      //cout<<n<<" "<<m<<endl;
        vector<int> v[n+1], vr[n+1];
        if(n==0 && m==0)
            break;
        initi(n);
        map<string,int> ms;
        string s,s1;
        getline(cin,s);
        fre(i,n)
        {
            getline(cin,s);
            //cout<<s<<endl;
            ms[s] = i;
        }
        fr(i,m)
        {
            getline(cin,s);
            getline(cin,s1);
            x = ms[s];
            y = ms[s1];
            v[x].pb(y);
            vr[y].pb(x);
        }
        fre(i,n)
        {
            if(!visited[i])
              dfs(i,v);
        }

        ll ans =  0;
        //initi(n);

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
                  size = vr[z].size();

                  fr(i,size)
                  {
                      if(visited[vr[z][i]])
                      {
                         visited[vr[z][i] ] = false;
                         st.push(vr[z][i]);
                      }
                  }
              }
            }
        }
        cout<<ans<<endl;
        
    }

}

