#include<bits/stdc++.h>
using namespace std;

bool isprime[35];

int ans[17];
bool visited[17] = {false};

void init()
{
	isprime[1] = isprime[2]= isprime[3] = true;
	
	for(int i=4; i<35; i++)
	{
		isprime[i]=true;
		if(i%2==0)
			isprime[i]=false;
		else
		{
			for(int j=3; j<=i/2; j+=2)
			{
				if(i%j==0)
				{
					isprime[i]=false;
					break;
				}
			}
		}
		
	}
	
	
}

bool print(int n, int pos)
{
    if(pos==n)
    {
	if(isprime[1+ans[n-1]])
	{
		for(int i=0; i<n; i++)
		        {
		            cout<<ans[i];
		            if(i==n-1)
		                cout<<endl;
		            else
		                cout<<" ";
		        }
	}
           
        
    }
    for(int i=2; i<=n ; i++)
    {
        if(visited[i]==false && isprime[i+ans[pos-1]] == true)
        {
            ans[pos]= i;
            visited[i] = true;
            if(print(n,pos+1))
                return true;

            visited[i] = false;
        }
    }
    return false;
}

int main()
{
	
	
	
	init();
    int i=1,n;
    while(cin>>n)
    {
	if(i!=1)
		cout<<endl;
        for(int j=0; j<17; j++)
    		visited[j] = false;
        cout<<"Case "<<i<<":"<<endl;
        if(n==1)
            cout<<"1"<<endl;
        else if(n==2)
            cout<<"1 2"<<endl;
        else
        {
                   	ans[0]=1;
	        visited[1] = true;
	        bool x =  print(n, 1);
	        
        }
        i++;
        
    }
}
