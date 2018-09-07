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

bool f(string s, string s1)
{
   ll n = s.length();
   ll m = s1.length();

   ll pre[m];
   pre[0] = 0;
   ll i=1, j=0;
   
   while(i<m)
   {
      if(s1[i] == s1[j]) 
         pre[i]=j+1, j++, i++;
      else
      {
         if(j==0)
             pre[i]=0,i++;
         else
            j = pre[j-1];
      }
   }
  // fr(i,m)
    //  cout<<pre[i]<<" ";
   i = 0; j=0;
   bool is = false;
   while(i<n)
   {
      //out<<i<<" "<<j<<endl;
      if(s[i]==s1[j])
      {
         i++, j++;
         if(j==m)
         {
               is = true;
               j = pre[j-1];
         }  
      }  
      else
      {
         if(j==0)
            i++;
         else
            j = pre[j-1];  
      }
      

   }
   return is;
}
int main()
{
  
   ll t,q;
   string s,s1,ans;
   cin>>t;
   while(t--)
   {
      
      cin>>s;

      ll q;
      cin>>q;
      while(q--)
      {
         cin>>s1;
         //cout<<s<<" "<<s1<<endl;
         bool is = f(s,s1);

         ans = "n\n";
         if(is)
            ans= "y\n";
         cout<<ans;;
      }

   }


   

}
