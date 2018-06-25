#include <iostream>
#define ll long long int
using namespace std;

int main() 
{
	int a[5] = {1,5,10,20,100};
	ll n;
	cin>>n;
	ll ans = 0;
	ans+= n/100;
	n-=(n/100)*100;
	ans+=n/20;
	n-=(n/20)*20;
	ans+=n/10;
	n-=(n/10)*10;
	ans+=n/5;
	n-=(n/5)*5;
	ans+=n;
	cout<<ans<<endl;

	
}
