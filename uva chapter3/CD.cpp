#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> v;
int s = -1;
void maxnum(int* a, int t, int pos, int n, vector<int> ve,int sum)
{
	if(sum>t)
		return;
	if(s<sum)
	{
		v=ve;
		s = sum;
	}
	if(pos>=n)
		return;
	if(a[pos]>t)
		(a,t,pos+1,n);
	else
	{
		ve.push_back(a[pos]);
		maxnum(a,t,pos+1,n,ve,sum+a[pos]);
		ve.pop_back();
		maxnum(a,t,pos+1,n,ve,sum);
	}
}
int main() 
{
    int t;
    while(cin>>t)
    {
        int n;
        cin>>n;
        int a[n];
        vector<int> ve;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
          
        }
        maxnum(a,t,0,n,ve,0);
        int size =v.size();
        int sum=0;
        for(int i=0; i<v.size(); i++)
        {
        	cout<<v[i]<<" ";
        	sum+=v[i];
        }
        cout<<"sum:"<<sum<<endl;	
	
		s = -1;
        
    }
      
}

