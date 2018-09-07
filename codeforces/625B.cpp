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
   string a,b;

   cin>>a>>b;
   ll n = a.length();
   ll m = b.length();
   vector<ll> v;

   ll pre[m]={0};
   ll i = 1, j =0;

   while(i<m)
   {
      if(b[i]==b[j])
         pre[i] = j+1, j++, i++;
      else 
      {
         if(j==0)
               i++;
         else
            j = pre[j-1];
      }
   }

   i = 0, j=0;
   while(i<n)
   {
      if(a[i] == b[j])
         i++, j++;
      else 
      {
         if(j==0)
            i++;
         else
            j = pre[j-1];
      
      }
      if(j==m)
         v.pb(i+1-m);
   }

   ll size = v.size();

   ll prev = -1;
   ll ans = 0;
   fr(i,size)
   {
     
      //cout<<v[i]<<" "<<prev<<endl;
      if(v[i] > prev)
      {
         ans++;
         prev = v[i]+m-1;
      }
      
   }
   cout<<ans<<endl;

}
