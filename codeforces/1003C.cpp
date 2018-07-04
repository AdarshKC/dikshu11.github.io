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
   
    ll n,k;
    cin>>n>>k;
    
    double a[n+1];
    a[0] = 0;
    
    fre(i,n)
    {
    	cin>>a[i];
    	a[i]+= a[i-1];
    }
    double ans = -1;
    for(ll i=k; i<=n; i++)
    {
    	for(ll j=0; j<=i-k; j++)
    	{
    		double ab = a[i]-a[j];
    		
    			ab/=(i-j);
    		
    			
    		if(ab>ans)
    			ans = ab;
    	}
    }
    printf("%0.12f",ans);
	
   
    
}
