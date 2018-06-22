#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() 
{
	ll n;
	cin>>n;
	string s;
	cin>>s;
	//cout<<s<<endl;
	for(int i=1; i<=n; i++)
	{
		if(n%i==0)
		{
		
			reverse(s.begin(), s.begin()+i );
			//cout<<s<<endl;
		}
	}
	cout<<s<<endl;
}
