#include<bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio (false) ; 
    cin.tie(0) ; cout.tie(0) ;
   
   ll n,x,y;
   cin>>n>>x>>y;
   
   ll a[n];
   vector< ll > v;
   
   for(int i=0; i<n; i++)
   {
   	char x;
   		cin>>x;
   		
   		a[i] =  x-'0';
   		if(a[i]==0)
   			v.push_back(i);
   }
   ll ans = 0;
  
   ll size = v.size();
   if(size==0)
	cout<<"0"<<endl;
   else if(y<=x)
   {
		ll ans = 1;
   		ll i=1;
   		ll prev = v[0];
   		while(i<size)
   		{
   		//	cout<<v[i]<<" "<<ans<<" "<<prev<<endl;
   			if(v[i]!=prev+1)
   				ans++;
   			 prev = v[i];
   				
   			i++;
   		}
   	//	cout<<ans<<endl;
   		cout<<(ans)*y<<endl;	
   }
   else
   {
   		ll ans = 1;
   		ll i=1;
   		ll prev = v[0];
   		while(i<size)
   		{
   			if(v[i]!=prev+1)
   				ans++;
   			prev = v[i];
   				
   			i++;
   		}
   		cout<<(ans-1)*x+y<<endl;
   }
    
}
