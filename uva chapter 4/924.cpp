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

	ll t, n=0,num, size,x,y;
	cin>>n;
	vector<ll> v[n+1];
	fr(i,n)
	{
		cin>>x;
		while(x--)
		{
			cin>>y;
			v[i].pb(y);
		}
	}
	cin>>t;
 	while(t--)
 	{
 			cin>>x;

 			bool visited[n+1] = {false};
 			ll level[n+1], freq[2500+100]={0};
 			level[x] = 1;
 			visited[x] = true;
 			ll  num=1, lm=0,ind;
 			queue<ll> q;
 			q.push(x);
	 		while(!q.empty())
	 		{
	 			ll z = q.front();
	 			q.pop();
	 			size = v[z].size();
	 			fr(i,size)
	 			{
	 				if(!visited[v[z][i]])
	 				{
	 					visited[v[z][i]] = true;
	 					level[v[z][i]] = level[z]+1;
	 					q.push(v[z][i]);
	 					num++;
	 					freq[level[z]+1]++;
	 					if( freq[level[z]+1] > lm)
	 					{
	 						lm = freq[level[z]+1];
	 						ind = level[z]+1;
	 					}
	 				}
	 			}
	 		}
	 		if(num==1)
	 			cout<<"0"<<endl;
	 		else
	 		{
	 			cout<<lm<<" "<<ind-1<<endl;
	 		}

	}



	
}
