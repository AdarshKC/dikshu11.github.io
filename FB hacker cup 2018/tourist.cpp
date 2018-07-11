/*
Tourist
Overall, Alex will want to first see attractions 1 to N in order,
then see them all a second time in the same order, then all a 
third time in the same order, and so on. 
If we write out an infinite sequence of attractions 
1, 2, ..., N-1, N, 1, 2, ..., N-1, N, 1, ..., then 
Alex will see the first K attractions in this list on his first visit,
the next K on his second visit, and so on. This means that, 
on his Vth visit, Alex will see the (K*(V-1)+i)th attraction in the 
list for i=1..K. We can convert each of these values into its 
corresponding attraction index between  1 and N using modulus,
sort these indices in increasing order, 
and then output their corresponding attraction names in that order.
*/
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

	ll t;
	cin>>t;
	ll num = 0;
	while(t--)
	{
		num++;
		ll n,k,v;
		cin>>n>>k>>v;
		
		string s[n];
		
		fr(i,n)
			cin>>s[i];
			
		ll a[n][n+1];
		
		fr(i,n)
			a[i][0] = 0;
		ll end = 0;
	
		fre(i,n)
		{
			fr(j,n)
				a[j][i] = a[j][i-1];
			
			ll t = end;	
			for(ll j= end; j<end+k; j++)
			{
				//cout<<j%n<<" "<<i<<endl;
				a[j%n][i]++;
				t = (t+1)%n;
			}
			end = t;
			
		}
		/* fr(i,n)
		{
			fr(j,n+1)
			{
				cout<<a[i][j]<<" ";	
			}
			cout<<endl;
		} */
		ll z =  v%n;
		if(z==0)
			z=n;
		cout<<"Case #"<<num<<": ";
	//	cout<<z<<endl;
		fr(i,n)
		{
		//	cout<<a[i][z]<<" "<<a[i][z-1]<<endl;
			if(a[i][z] > a[i][z-1])
				cout<<s[i]<<" ";
		}
		cout<<endl;
	}
}
