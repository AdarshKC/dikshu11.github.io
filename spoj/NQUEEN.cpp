#include <iostream>
#include<vector>
using namespace std;
 
bool pos(int* a, bool* visited, int row, int n,vector<pair<int,int>> v)
{
	if(row==n)
	{
		for(int i=0; i<n; i++)
			cout<<a[i]<<" ";
		return true;
	}
	if(visited[row]==false)
	{
		
		int col;
		for(col=0; col<n; col++)
		{
			bool safe = true;
			for(int j=0; j<row; j++)
			{
				if( col==a[j] || row+col==j+a[j] || row-col==j-a[j])
				{
						
						safe=false;
						break;
						
				}
			}
			int size = v.size();
			for(int j=0; j<size; j++)
			{
				if( col==v[j].second || row+col==v[j].first+v[j].second || row-col==v[j].first-v[j].second)
				{
						
						safe=false;
						break;
						
				}
			}
			if(safe)
			{
				a[row]=col;
				if(pos(a,visited,row+1,n,v))
					return true;
			}
		}
		return false;
	}
	else
		return(pos(a,visited, row+1,n,v));
		
 
	
}
int main() 
{
	int n;
	while(cin>>n)
	{
		int a[n];
		bool visited[n] = {false};
		vector<pair<int,int>> v;
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
			if(a[i])
			{
				visited[i]=true;
				v.push_back(make_pair(i,a[i]));
			}
			
				
		}
		
		bool x = pos(a,visited,0,n,v);
		cout<<endl;
	}
	
} 
