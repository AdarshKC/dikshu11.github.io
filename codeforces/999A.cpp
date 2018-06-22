#include <iostream>
#define ll long long int
using namespace std;

int main() 
{
	ll n,k;
	cin>>n>>k;
	ll a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
		
	ll end=-1,ans=0;
	for(int i=0; i<n; i++)
	{
		if(a[i]>k)
		{
			end = i;
			break;
		}
		else
			ans++;
	}
	if(end==-1)
		end = n;
	for(int i=n-1; i>end; i--)
	{
		if(a[i]>k)
		{
			break;
		}
		else
			ans++;
	}
	cout<<ans<<endl;
}
