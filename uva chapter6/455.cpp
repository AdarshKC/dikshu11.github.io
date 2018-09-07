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
   
   ll t;
   cin>>t;
   while(t--)
   {
      string b;
      cin>>b;
      ll m = b.length();

      ll pre[m]={0};
      ll i = 1, j =0, ans = 0;

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

      i = m-1;
      ll z = pre[m-1];

      while(i>=0)
      {
         if(pre[i]!=z || pre[i]==1)
            break;
         i--, z--;
      }
      string a = "";

      fr(k, i)
         a+= b[k];

      ll len=a.length(), ind = 0;
      if(len==0 || len==m)
         ans = 0;
      else if(m%len!=0)
         ans = 0;
      else
      {

         fr(i,m)
         {
            if(ind==len)
            {
               ind=0;
               ans++;
            }   
            if(b[i]==a[ind])
                ind++;
            else
            {
               ans=0;
               break;
            }

         }
      }
      if(ans==0)
         cout<<m<<endl;
      else
         cout<<len<<endl;
      
      if(t!=0)
         cout<<endl;
      
   }
}

