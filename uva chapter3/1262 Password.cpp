#include<bits/stdc++.h>
using namespace std;
char ans[5];
set<string> s;
void find(int pos, vector<char> v[])
{
	if(pos==5)
	{
		string sans;
		for(int i=0; i<5; i++)
			sans+=ans[i];
		s.insert(sans);
		return; 
	}
	int size = v[pos].size();
	for(int i=0; i<size; i++)
	{
		ans[pos] = v[pos][i];
		find(pos+1,v);
	}
}



int main()
{
	int m,k;
	char w;
	cin>>m;
	while(m--)
	{
		cin>>k;
		set<char> sx[5];
		set<char> :: iterator it;
		vector<char> v[5];
		for(int j=0; j<6; j++)
		{
			for(int i=0; i<5; i++)
			{
				cin>>w;
				sx[i].insert(w);
			}
		}
		for(int j=0; j<6; j++)
		{
			for(int i=0; i<5; i++)
			{
				cin>>w;
				it = sx[i].find(w);
				if(it!=sx[i].end())
					v[i].push_back(w);
			}
		}
		
		find(0,v);
		if(s.size()<k)
			cout<<"NO"<<endl;
		else
		{
			vector<string> ve(s.begin(), s.end());
			cout<<ve[k-1]<<endl;
		}	
			
		s.clear();
		
		
	}
}
