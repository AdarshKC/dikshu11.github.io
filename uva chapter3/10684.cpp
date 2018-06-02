#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ll n,x;
	while(cin>>n && n!=0)
	{
	
		 ll maxend=0, maxsum=0;
		 for(ll i=0; i<n; i++)
		 {
		 	cin>>x;
		 	maxend+=x;
		 	if(maxend<0)
		 		maxend=0;
		 	if(maxend>maxsum)
		 		maxsum= maxend;
		 }
		 if(maxsum>0)
		 	cout<<"The maximum winning streak is "<<maxsum<<"."<<endl;
		 else
		 	cout<<"Losing streak."<<endl;
	}	


	
}
