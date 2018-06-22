#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() 
{
	ll n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	
	vector<ll> v[26];
	bool con[n];
	for(ll i=0; i<n; i++)
	{
		int x = s[i]-'a';
		v[x].push_back(i);
		con[i] =  false;
	}
	ll i = 0, ind = 0, sum = 0;;
	while(sum<k)
	{
		if(ind==v[i].size())
		{
			i++;
			ind = 0;
		}
		else
		{
			con[ v[i][ind] ] = true;
			ind++;
			sum++;
		}

	}
	for(ll i=0; i<n; i++)
	{
		if(con[i]==false)
			cout<<s[i];
	}
	


}
