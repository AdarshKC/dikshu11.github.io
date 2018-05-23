#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> v;
bool isPos(int se, int num, bool* visited , int eb)
{
	if(n==num)
	{
		if(se==eb)
			return true;
	
	}
	for(int i=0; i<m; i++)
	{
		if(visited[i] == false && v[i].first == se)
		{
			visited[i] = true;
			if( isPos( v[i].second , num+1, visited, eb ) )
				return true;

			visited[i] = false;
		}
		if(visited[i] == false && v[i].second == se)
		{
			visited[i] = true;
			if( isPos( v[i].first , num+1, visited, eb ) )
				return true;

			visited[i] = false;
		}
	}
	return false;
}
int main()
{

	while(cin>>n && n)
	{
		cin>>m;		
		int sb,se,eb,ee;
		cin>>sb>>se>>eb>>ee;
		bool visited[m];
		int x,y;
		for(int i=0; i<m; i++)
		{
			visited[i] = false;
			cin>>x>>y;
			v.push_back(make_pair(x,y));
			
		}	
		bool z =isPos(se, 0, visited,eb);
		if(z)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

		v.clear();
	}

}
