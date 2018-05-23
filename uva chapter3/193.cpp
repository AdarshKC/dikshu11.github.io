#include<bits/stdc++.h>
using namespace std;
vector<int> ve;
int m,n,k;
int s =-1;

void find(vector<int> v[], int* visited, int pos, vector<int> vans, int sum)
{
	if(s<=sum)
	{
		s = sum;
		ve = vans;
	}
	if(pos==n+1)
		return;

	if( visited[pos]==0 )
	{
		vans.push_back(pos);
		visited[ pos ]++;
		int size = v[pos].size();
		
		for(int i=0; i<size; i++)
			visited[ v[pos][i] ]++;

		find(v,visited, pos+1, vans, sum+1);
		
		vans.pop_back();

		for(int i=0; i<size; i++)
			visited[ v[pos][i] ]--;

	
		
		visited[pos]--;

	}
		find(v,visited, pos+1, vans, sum);

}

int main()
{
	
	cin>>m;
	while(m--)
	{
		cin>>n>>k;
		vector<int> v[n+1], vans;
		int visited[n+1]  = {0};

		for(int i=0; i<k; i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
			find(v,visited,1, vans, 0);
		int size = ve.size();
		cout<<size<<endl;
		for(int i=0; i<size; i++)
		{
			cout<<ve[i];
			if(i==size-1)
				cout<<endl;
			else
				cout<<" ";
		}	
		s =-1;

		ve.clear();
	}
}
