#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void create(ll* a, ll *s,ll* lazy, ll low, ll high, ll pos)
{
    if(low==high)
    {
        s[pos] = a[low];
        lazy[pos] =0;
        return;
    }
    ll mid =(low + high)/2;
    create(a,s,lazy,low,mid,2*pos+1);
    create(a,s,lazy,mid+1,high, 2*pos+2);
     lazy[pos] =0;
    s[pos] = s[2*pos+1] + s[2*pos+2];
}

ll getsum(ll* s,ll* lazy, ll l , ll h, ll low, ll high, ll pos)
{
  
    if(lazy[pos]!=0)
    {
        s[pos]+= (high-low+1)*lazy[pos];
        if(high!=low)
        {
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos]=0;
    }

     if(l>high || h<low)
        return 0;

    if(l<=low && h>= high)
        return s[pos];

    ll mid =(low + high)/2;
    return getsum(s,lazy,l,h,low,mid,2*pos+1) + getsum(s,lazy,l,h,mid+1,high, 2*pos+2);
}

void update(ll* s,ll* lazy ,ll l, ll h, ll val, ll low, ll high, ll pos)
{

    if(lazy[pos]!=0)
    {
        s[pos]+=(high-low+1)*lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos]=0;
    }
    if(h<low || l>high)
        return;

    if(l<=low && h>=high)
    {
        s[pos]+=(high-low+1)*val;
        if(high!=low)
        {
            lazy[2*pos+1]+=val;
            lazy[2*pos+2]+=val;
        }
        return;
    }
    int mid = (low+high)/2;
    update(s,lazy,l,h,val,low,mid,2*pos+1);
    update(s,lazy,l,h,val,mid+1,high,2*pos+2);
    s[pos] = s[2*pos+1] + s[2*pos+2];
    
}
int main()
{   
    ll t,p,q,v;
    cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;

        ll a[n];
        for(int i=0; i<n; i++)
            a[i]=0;
        ll s[4*n];
        ll lazy[4*n];
        int x;
        create(a,s,lazy, 0,n-1,0);
        while(c--)
        {
            cin>>x;
            if(x==0)
            {
                cin>>p>>q>>v;
                p--,q--;
               update(s,lazy,p,q,v,0,n-1,0);
               
            }
            else
            {
                cin>>p>>q;
                p--,q--;
                ll ans = getsum(s,lazy,p,q,0,n-1,0);
                cout<<ans<<endl;
            }
        }
    }
}
