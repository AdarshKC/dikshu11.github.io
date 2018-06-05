#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
	
	ll n;
	vector<ll> v,z;
	while(cin>>n)
		v.push_back(n);

	n = v.size();
	ll hel[n];
	ll t[n];
	for(int i=0; i<n; i++)
	{
		hel[i] = -1;
	}	
	t[0] = 0;
	ll len = 0;
	for(int i=1; i<n; i++)
	{
		//cout<<len<<" "<<t[len]<<endl;
		if(v[i]>v[t[len] ])
		{
			len++;
			t[len] = i;
			hel[i] = t[len-1];
		}
		else if(v[i]<v[t[0]])
			t[0] = i;
		else
		{
			ll start = 0;
			ll end = len;
			ll mid;
			while(start<=end)
			{
				mid =   (end+start)/2;
				if(mid<len && v[t[mid]]<v[i] && v[t[mid+1]]>= v[i])
					break;
				else if(v[t[mid]]<v[i])
					start = mid+1;
				else
					end = mid -1;
			}
			if(mid==len)
			{
				t[mid] = i;
				hel[i] = t[mid-1];
			}
			else
			{
				t[mid+1] = i;
				hel[i] = t[mid];
			}	
		}


	}
	cout<<len+1<<endl<<"-"<<endl;
	ll index = t[len];
	while( index!=-1)
	{
		z.push_back(v[index]);
		index = hel[index];
	}
	n=z.size();
	for(ll i=n-1; i>=0; i--)
		cout<<z[i]<<endl; 
}
