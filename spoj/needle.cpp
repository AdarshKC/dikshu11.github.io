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
   while(cin>>t)
   {
      string a,b;
      cin>>a;
      getline(cin, b);
      getline(cin, b);
      //cout<<a<<b<<endl;
      std::size_t pos = b.find(a, 0);

      while(pos!= std::string::npos)
      {
         cout<<pos<<endl;
         pos = b.find(a, pos+1);
      }
      cout<<endl;
   }


   

}
