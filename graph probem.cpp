#include<bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
#define f(j,i,n) for(ll j=i; j<n; j++)
#define pb push_back
using namespace std;
 
int main() 
{
	ll n;
	cin>>n;
	
	/* Maps are used to map string to integer
	and integer to string so that we can make 
	adjacency vector
	*/
	map<string, ll> m;
	map< ll, string> m1;
	
	/* Map initial position to 0
	and destination to 1*/
	string a,b;
	cin>>a>>b;
	
	m[a] = 0, m[b] = 1;
	m1[0] = a, m1[1]=b;
	
	/* ind will store how many different 
	   strings(places) are there.
	*/
	ll ind = 2;
	vector<ll> v[2*100000];
	fr(i,n)
	{
		/* Taking input as string
		and making adjacency matrix */
		cin>>a>>b;
		ll x,y;
		map<string,ll> :: iterator it;
		it = m.find(a);
		if(it!= m.end())
			x= m[a];
		else
			m[a] = ind, x = ind,m1[ind] = a, ind++ ;
		
		it = m.find(b);
		
		if(it!= m.end())
			y= m[b];
		else
			m[b] = ind, y = ind, m1[ind] = b, ind++;	
			
		v[x].push_back(y);
		v[y].push_back(x);
		
		
	}
	/* DFS 
	parent[] will store parent node
	*/
	bool visited[ind] = {false};
	ll parent[ind];
	fr(i,ind)
		parent[i] = i;
	
	stack<ll> s;
	
	/* push starting node in stck
	*/
	s.push(0);
	visited[0] = true;
	while(s.empty() == false)
	{
		ll z = s.top();
		s.pop();

		ll size = v[z].size();
		fr(i,size)
		{
			if(visited[ v[z][i] ] == false)
			{
				parent[v[z][i] ] = z;
				visited[  v[z][i] ] = true;
				s.push( v[z][i] );
			}
		}
		
	}
	stack<ll> ans;
	ll i=1;
	
	/* Backtracking
	insert parent value in stack
	*/
	while(parent[i] != 0)
	{
		ans.push(parent[i]);
		i = parent[i];

	}
	/* Printing the path 
	destination is not inserted in ans
	So print it later
	*/
	while(!ans.empty())
	{
		ll z = ans.top();
		ans.pop();
		cout<<m1[z]<<" ";
	}
	cout<<m1[1];
}
