#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll Arr[100000*2+10000];
ll size[100000*2+10000];


int root(int i)
{
    while(Arr[i]!=i)
    {
    	Arr[ i ] = Arr[ Arr[ i ] ] ;
        i = Arr[i];
    }
    return i;
}

int un(int a, int b)
{
    int roota = root(a);
    int rootb = root(b);
    //cout<<"roota "<<roota<<"rootb"<<rootb<<endl;
    if(roota==rootb)
	return size[roota];
    else if(size[roota] < size[rootb] )
    {
        Arr[roota] = Arr[rootb];
        size[rootb] += size[roota];
        return size[rootb];
    }
    else 
    {
        Arr[rootb] = Arr[roota];
        size[roota] += size[rootb];
        return size[roota];
    }
     
}
int main()
{
    ll n;
    cin>>n;
    while(n--)
    {
       int t;
       cin>>t;
       map<string,int> m;
       map<string,int> :: iterator x;
       int i=0;
        while(t--)
        {
            string a,b;
            cin>>a>>b;

            int ia=-1,ib=-1;
            if(a!=b)
	{
		x = m.find(a);
	            if(x==m.end())
	            {
	                ia =i;
	                m[a] = ia;
	               
	                Arr[i]=i;
	                size[i]=1;
	                 i++;
	            } 
	            else
	               ia = x->second;
	            
	            x = m.find(b);
	            if(x==m.end())
	            {
	                ib =i;
	                m[b] = ib;
	               
	                Arr[i]=i;
	                size[i]=1;
	                i++;
	            }
	            else
	               ib = x->second;
	           
	            ll ans = un(ia,ib); 
	            cout<<ans<<endl;
	}
	else
	{
		 x = m.find(a);
	             if(x==m.end())
                           {
			m[a] = i;
			ia = i;
			Arr[i]=i;
	            	size[i]=1;
	            	i++;
		           	
		   }
		   else
	               ia = x->second;
	               
	            int roota = root(ia);
	            cout<<size[roota]<<endl;
	}
        }


    }

}
