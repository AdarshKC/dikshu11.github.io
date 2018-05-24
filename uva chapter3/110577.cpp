#include<bits/stdc++.h>
using namespace std;

int bs(int* a, int start, int end, int x)
{
	
	if(a[end]<x || a[start]>x )
		return -1;
	int mid;
	while(start<=end)
	{
		
		mid = (end-start)/2 + start;
		if(a[mid]==x)
			return mid;
		else if(a[mid]>x)
			end = mid-1;
		else
			start = mid+1 ;
	}
	return -1;
}

int main()	
{
	int n;
	while(cin>>n)
	{
		int a[n];
		for(int i=0; i<n; i++)
			cin>>a[i];
		int x;
		cin>>x;
		int l,h;
		int diff = 100000000;
	//	cout<<x<<" "<<diff;
		sort(a,a+n);
		for(int i=0; i<n; i++)
		{
			int ind = bs(a,0,n-1, x-a[i]);
		
			
			if(ind!=-1 && ind !=i)
			{
			//	cout<<a[i]<<" "<<a[ind]<<endl;
				if(abs(a[ind]-a[i])<diff)
				{

					diff = abs( a[ind]-a[i] );
					if(a[ind]-a[i] > 0)
						l = a[i], h = a[ind];
					else
						h = a[i], l = a[ind];
				}
			}
		}
		cout<<"Peter should buy books whose prices are "<<l<<" and "<<h<<"."<<endl;
		cout<<endl;
		string blank;
		getline(cin,blank);
		getline(cin,blank);
	}
}
