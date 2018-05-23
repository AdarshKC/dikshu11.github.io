#include<bits/stdc++.h>
using namespace std;
int flag=0;
vector< vector<int>> vans;
set<vector<int>> s;
set<vector<int>> :: iterator it;
void print(int* a, int n, int t, int sum, vector<int> v, int pos)
{
	if(sum>t)
		return;
	if(sum==t)
	{
		flag=1;
		sort(v.begin() , v.end());
		it = s.find(v);
		if(it==s.end() )
		{
			vans.push_back(v);
			s.insert(v);
		}
		return;
		
	}
	if(pos>=n)
		return;
			v.push_back(a[pos]);
			print(a,n,t, sum+a[pos], v, pos+1);
			v.pop_back();
			print(a,n,t, sum, v, pos+1);
}
int main()
{
	int t,n;
	while(cin>>t>>n && n!=0)
	{
			
		int a[n];
		for(int i=0; i<n; i++)
			cin>>a[i];
		flag=0;
		vector<int> v;
		cout<<"Sums of "<<t<<":"<<endl;
		print(a,n,t, 0,v,0);
		int vsize = vans.size();
		for(int j=0; j<vsize; j++)
		{
			v = vans[j];		
			int size =v.size();
			for(int i=size-1; i>=0; i--)
			{
				if(v[i]!=0)
					cout<<v[i];
				if(i==0)
					cout<<endl;
				else
					cout<<"+";
			}
		}
		vans.clear();
		if(!flag)
			cout<<"NONE"<<endl;
	}

}
