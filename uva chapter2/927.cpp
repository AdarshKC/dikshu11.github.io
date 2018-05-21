#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void zac(ll* b, ll* x,ll z)
{
	int carry = 0;
	for(int i=0; i<40; i++)
	{
		b[i]=x[i]*z+ carry;
		carry = b[i]/10;
		b[i]%=10;
	}	
}
void mult(ll* x, ll n)
{
	int carry = 0;
	for(int i=0; i<40; i++)
	{
		x[i]*=n;
		x[i]+=carry;
		carry = x[i]/10;
		x[i]%=10;
	}	
}
void getsum(ll* b, ll* sum)
{
	int carry = 0;
	for(int i=0; i<40; i++)
	{
		sum[i] += b[i]+carry;
		carry = sum[i]/10;
		sum[i]%=10;
	}
}
int main() 
{
    ll t,d,o;
    cin>>t;
	
    for(int k=0; k<t; k++) 
    {
        int power;
        cin>>power;
        ll coeff[power+1];
        for(ll i=0; i<=power; i++)
            cin>>coeff[i];
            
            cin>>d>>o;
	double z = sqrt(1+(8*o)/d );
	z+= -1;
	z/=2;
	ll n = ceil(z);
	ll x[40]={0};
	x[0] = 1;
	ll sum[40]={0};
	
            for(ll i=0; i<=power; i++)
            {
               ll b[40]={0};
               zac(b,x,coeff[i]);
               mult(x,n);
               getsum(b,sum);

            }
            int flag = 0;
            for(int i=39; i>=0; i--)
            {
            	if(sum[i]==0 && flag ==0)
            		continue;
            	if(sum[i]!=0)
            	{
            		cout<<sum[i];
            		flag=1;
            	}
            	if(sum[i]==0 && flag==1)
            		cout<<sum[i];
            }
            cout<<endl;
     
    }
}

