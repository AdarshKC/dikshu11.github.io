#include<bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
#define pb push_back
#define mp(i,j) make_pair(i,j)
#define fi first
#define se second
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio (false) ; 
    cin.tie(0) ; cout.tie(0) ;
	
    ll n;
    cin>>n;
    char a[n+1] , b[n+1];
    ll ans = 0;
    
    fre(i,n)
	cin>>a[i];
    fre(i,n)
	cin>>b[i];

    ll z = n/2;
    
    fre(i,z)
    {
    	ll ind = n-i+1;
    	if(a[i]== b[i] && a[ind]==b[ind])
    		ans+=0;
    	else if(a[i]==b[i] && a[ind]!= b[ind])
    		ans++;
    	else if(a[ind]==b[ind] && a[i]!= b[i])
    		ans++;
    	else 
    	{
    		set<char> s;
    		s.insert(a[i]);
    		s.insert(b[i]);
    		s.insert(a[ind]);
    		s.insert(b[ind]);
    		
    		if(s.size()==4)
    			ans+=2;
    		else if(s.size()==3)
    		{
    			ans++;
    			if(a[i]==a[ind] )
    				ans++;
    		}
    	}
    		
    }
    
   if(n%2)
   {
	if(a[z+1]!=b[z+1])
		ans++;
   }
   cout<<ans<<endl;

}
