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
    int n,m,x,y,z,size, tp = 0;;
    while(cin>>n>>m)
    {
      //cout<<n<<" "<<m<<endl;
      if(n==0 && m==0)
            break;
        if(tp!=0)
          cout<<endl;
        tp++;
        cout<<"Calling circles for data set "<<tp<<":"<<endl;
        vector<int> v[n+1], vr[n+1];
        
        initi(n);
        map<string,int> ms;
        map<int, string> mls;
        string s,s1;
        int num = 1;
        fr(i,m)
        {
            cin>>s>>s1;

            map<string,int> :: iterator it;
            it = ms.find(s);
            if(it==ms.end())
            {
               ms[s] = num;
               mls[num] = s;
               num++;
            }
            it = ms.find(s1);
            if(it==ms.end())
            {
               ms[s1] = num;
               mls[num] = s1;
               num++;
            }
            
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
              
              vector<ll> ans;
              stack<ll> st;
              st.push(z);
              visited[z] = false;

              while(!st.empty())
              {
                  z = st.top();
                  st.pop();
                  ans.pb(z);
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
              size = ans.size();

              fr(j,size)
              {
                 cout<<mls[ ans[j] ];
                 if(j!=size-1)
                    cout<<", ";
                 else
                    cout<<endl;
              }
            }
        }
      
        
    }

}

