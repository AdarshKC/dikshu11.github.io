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
   ll t,n,m,i,j;
   cin>>t;
 
   while(t--)
   {
      //cout<<t<<" kssgr"<<endl;
      vector<ll> v;
      string a,b;
      cin>>a>>b;
 
      n = a.length();
      m = b.length();
 
      ll pre[m];
      i=1, j=0;
      pre[0] = 0;
      while(i<m)
      {
         if(b[i]==b[j])
            pre[i] = j+1, i++, j++;
         else if(b[i]!=b[j])
         {
            if(j==0)
               pre[i]=0, i++;
            else
               j = pre[j-1];
         }
 
      }
      i=0, j=0;
      while(i<n)
      {
         if(a[i]==b[j])
         {
            i++, j++;
            if(j==m)
            {
               v.pb(i+1-m);
               j = pre[j-1];
            }
         }
         else
         {
            if(j==0)
                  i++;
            else
               j =pre[j-1];
         }
      }
      if(v.size()==0)
         cout<<"Not Found\n";
      else
      {
         ll size = v.size();
         cout<<size<<endl;
         fr(i,size)
            cout<<v[i]<<" ";
         cout<<endl;
      }
      cout<<endl;
   }
} 
