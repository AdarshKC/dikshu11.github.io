
 #include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() 
{
	ll a,b,c,n;
	cin>>a>>b>>c>>n;
	
	if(a+b-c>=n)
		cout<<"-1"<<endl;
	else if(a<c || b<c)
		cout<<"-1"<<endl;
	else
		cout<<n-(a+b-c)<<endl;
}
