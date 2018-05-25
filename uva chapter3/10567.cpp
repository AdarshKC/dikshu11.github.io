#include<bits/stdc++.h>
using namespace std;


int bs(int start, int end, int x, vector<int> v)
{
	if(v[end]<x)
		return -1;
	if(v[start]>=x)
		return v[start];
	int mid;
	while(start<=end)
	{
		 mid = (end-start)/2 + start;
		if(start==end)
			return v[mid];
		if(v[mid]==x)
			return v[mid];
		else if(v[mid]>x)
			end = mid;
		else
			start = mid+1;
	}
	return -1;
}
int main()
{
	string s;
	cin>>s;
	vector<int> vu[26];
	vector<int> vl[26];
	int size = s.length();
	
	for(int k=0; k<size; k++)
	{
		char x = s[k];
		if(isupper(x))
		{
			int ind = x-'A';
			vu[ind].push_back(k);
		}
		else
		{
			int ind = x-'a';
			vl[ind].push_back(k);
		}
	}
	for(int i=0; i<26; i++)
	{
		sort(vu[i].begin(), vu[i].end());
		sort(vl[i].begin(), vl[i].end());
	}
	int n;
	cin>>n;
	string in;
	while(n--)
	{
		cin>>in;
		int ind, index, flag = 0;
		int start = -1, end = -1;
		size = in.length();
		for(int k=0; k<size; k++)
		{
			if(isupper(in[k]))
			{
				ind = in[k]-'A';
				index = bs(0, vu[ind].size()-1, end+1, vu[ind]);			
			}	
			else
			{
				ind = in[k]-'a';
				index = bs(0, vl[ind].size()-1, end+1 , vl[ind]);			

			}	
			if(index==-1)
			{
				flag = 1;
				break;
			}
			else if(k==0)
				start = end = index;
			else 
				end = index;
				
			
		}
		if(flag)
			cout<<"Not matched"<<endl;
		else
			cout<<"Matched "<<start<<" "<<end<<endl;
	}
}
