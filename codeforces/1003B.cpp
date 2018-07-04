#include<bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
#define pb push_back
#define mp(i,j) make_pair(i,j)
#define fi first
#define se second
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio (false) ; 
    cin.tie(0) ; cout.tie(0) ;
    
    ll a,b,x,z,flag;
    cin>>a>>b>>x;
  
    string s="";
    
    if(a>b)
	z=0, flag=0, s+='0', a--;
    else
	z=1, flag=1, s+='1', b--;

   
    while(x)
    {
	
	if(flag==1)
		s+='0', a--, flag=0;
	else
		 s+='1', b--, flag=1;
		
	x--;
    }
    
   //cout<<s<<endl;
    string w="",y="";
    while(a)
    {
    	w+='0';
    	a--;
    }
    while(b)
    {
    	y+='1';
    	b--;
    }
    char start = s[0], end = s[s.size()-1];
    if(start == end)
    {
    	
    	if(start=='1')
    	{
    		cout<<y;
    		ll size = s.size();
    		fr(i,size-1)
    			cout<<s[i];
    		cout<<w<<end<<endl;
    	}
    	else
    	{
    		cout<<w;
    		ll size = s.size();
    		fr(i,size-1)
    			cout<<s[i];
    		cout<<y<<end<<endl;
    	}
    }
    else if(z==1)
    {
    	cout<<y<<s<<w;
    }
    else
	cout<<w<<s<<y;
}
