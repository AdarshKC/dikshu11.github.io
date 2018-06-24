#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll can(ll mid, ll n)
{
	ll eat=0;
	ll total = n;
	while(total!=0)
	{
		if(total<mid)
		{
			eat+=total;
			total = 0;
		}
		else
		{
			eat+=mid;
			total -= mid;
			total -= (total)/10;
		}
	}
	return eat;
}

int main() 
{
	ll n;
	cin>>n;
	ll start = 1, end = n;
	ll mid;
	ll ans = start;
	while(start<=end)
	{
		ll mid = (start+end)/2;
		ll eat =  can(mid,n);
	//	cout<<eat<<" "<<start<<" "<<end<<" "<<mid<<endl;
		if(start==end)
		{
			if(eat*2 >= n )
			{
				ans = mid;
				end = mid;
			}
			break;
		}
		if(eat*2 >= n )
		{
			ans = mid;
			end = mid;
		}
		else
			start = mid+1;
			
	}
	cout<<ans<<endl;



}
