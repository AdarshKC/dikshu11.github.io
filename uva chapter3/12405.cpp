#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
	ll t;
	cin>>t;
	ll num = 1;
	while(num<=t)
	{

		ll ans = 0;
		ll n;
		cin>>n;
		char a[n];
		bool visited[n];
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
			if(a[i]=='#')
				visited[i] = true;
			else 
				visited[i] = false;
		}	
		for(int i=0; i<n; i++)
		{
			if(visited[i]==false)
			{
				if(i+1<n)
				{
					visited[i] = true;
					visited[i+1] = true;
					if(i+2<n)
						visited[i+2] = true;
				}
				else if(i+1==n)
				{
					visited[i] = true;
				}
				ans++;
			}

		}
		cout<<"Case "<<num<<": "<<ans<<endl;
		num++;
	}
}
