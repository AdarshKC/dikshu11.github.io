#include<bits/stdc++.h>
#define ll long long int
using namespace std;


void create(int* a, int* s, int low, int high, int pos)
{
   if(low==high)
   {
   	if(a[low]<0)
		s[pos] = (-1);
	else if(a[low]>0) 
		s[pos] =1;
	else
		s[pos]=2;
		
	return;
   }
   else
   {
        int mid = (high+low)/2;
        create(a,s,low,mid,2*pos+1);
        create(a,s,mid+1,high,2*pos+2);
        int x = s[2*pos+1]*s[2*pos+2];
        if(x==-1 || x==1)
		s[pos] = x;
        else
		s[pos] = 2;
        
   } 
}

int multi(int* s, int l, int h, int low, int high, int pos)
{
    if(l>high || h<low)
        return 1;
    if(l<=low && h>=high)
        return s[pos];
    int mid = (high+low)/2;

    return multi(s,l,h,low,mid,2*pos+1)*multi(s,l,h,mid+1, high, 2*pos+2);
}

void update(int* s,int z,int ind, int low, int high, int pos)
{
    if(ind<low || ind>high)
        return;
    if(low==high)
    {
	if(z<0)
		s[pos] = (-1);
	else if(z>0) 
		s[pos] =1;
	else
		s[pos]=2;	
    }
    int mid = (high+low)/2;
    if(low!= high)
    {
        update(s,z,ind,low,mid,2*pos+1);
        update(s,z,ind,mid+1,high,2*pos+2);
        int x = s[2*pos+1]*s[2*pos+2];
        if(x==-1 || x==1)
		s[pos] = x;
        else
		s[pos] = 2;
        
    }
}

int main()
{   
    int n,x,y,z;
    while(cin>>n>>x)
    {
        int a[n];
        int s[4*n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        create(a,s,0,n-1,0);
        for(int i=0; i<x; i++)
        {
            char c;
            cin>>c>>y>>z;
            if(c=='C')
            {
                y--;
                  update(s,z,y,0,n-1,0);
            }
            else
            {
                y--,z--;
                int ans = multi(s,y,z,0,n-1,0);
                if(ans==1)
                    cout<<"+";
                else if(ans==(-1) )
                    cout<<"-";
                else
                    cout<<"0";
            }
        }
        cout<<endl;
    }
}
