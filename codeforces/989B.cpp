#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, p;
    cin>>n>>p;
    string s;
    cin>>s;
    int flag = 0;
    for(int i=0; i<n-p; i++)
    {
	bool a1=false,a0=false,a=false;
	for(int j=i; j<n; j+=p)
	{
		if(s[j]=='.')
			a=true;
		else if(s[j]=='1')
			a1=true;
		else if(s[j]=='0')
			a0=true;
	}
	
	if( a1&&a0 )
		flag=1;
	else if(a1==true && a == true  && a0==false)
	{
		for(int  j=i; j<n; j+=p)
		{
			if(s[j]=='.')
				s[j]='0';
			if(j!=i)
				flag=1;
		}
	}
	else if(a0==true && a == true && a1==false)
	{
		for(int  j=i; j<n; j+=p)
		{
			if(s[j]=='.')
				s[j]='1';
			if(j!=i)
				flag=1;
		}
	}
	else if(a==true && a1==false && a0==false)
	{
		char x = '0';
		for(int  j=i; j<n; j+=p)
		{
			if(s[j]=='.')
			{
				s[j]=x;
		
			}
			if(j!=i)
				flag=1;
			
		}
		s[i]='1';
	}
    }
    if(flag==1)
    {
    	for(int i=0; i<n; i++)
    	{
    		if(s[i]!='.')
    			cout<<s[i];
    		else
    			cout<<"0";
    	}
    	
    }
    else
	cout<<"No";
    
}
