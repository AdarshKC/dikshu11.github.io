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

	ll t;
	cin>>t;
 	while(t--)
 	{
 		ll  n=0,num, size,x,y,i=0;
 		map<string, int> ms;
	 	vector<string> vs;
	 	string s,s1,ws;

	 	
	 	while(cin>>s)
	 	{
	 		
	 		if(s=="*")
	 			break;
	 		vs.pb(s);
	 		ms[s] = n;
	 		n++;
	 	}
	 	vector<ll> v[n+5];
		
	 	fr(i,n)
	 	{
	 		for(int j=i+1; j<n; j++)
	 		{
	 			num = 0;
	 			if(vs[i].length() == vs[j].length() )
	 			{
	 				size = vs[i].length();
	 				fr(k,size)
	 					if(vs[i][k] != vs[j][k] )
	 						num++;

	 				if(num==1)
	 				{
	 					v[i].pb(j);
	 					v[j].pb(i);
	 				}
	 			}
	 		}
	 	}
		
		getline(cin,ws);
	 	while(getline(cin,ws))
	 	{
	 		if(ws.length()==0)
	 			break;
	 		vector <string> tokens;
	 		stringstream check1(ws);
     
			    string intermediate;
			     
			    while(getline(check1, intermediate, ' '))
			    {
			        tokens.push_back(intermediate);
			    }
			s= tokens[0];
			s1 = tokens[1];
	 		x = ms[s];
	 		y = ms[s1];
	 		ll level[n+1];
	 		bool visited[n+1] = {false};

	 		queue<ll> q;
	 		q.push(x);
	 		visited[x] = true;
	 		level[x] = 0;
	 		while(!q.empty())
	 		{
	 			ll z = q.front();
	 		//	cout<<vs[z]<<" "<<z<<endl;;
	 			q.pop();
	 			size = v[z].size();
	 			fr(i,size)
	 			{
	 				if(!visited[v[z][i]])
	 				{
	 					visited[v[z][i]] = true;
	 					level[v[z][i]] = level[z]+1;
	 					q.push(v[z][i]);
	 				}
	 			}
	 		}
	 		cout<<s<<" "<<s1<<" "<<level[y]<<endl;
	 	}
	 	if(t!=0)
	 		cout<<endl;
 	}

}
