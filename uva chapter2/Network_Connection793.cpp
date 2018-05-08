#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int root(ll i, ll Arr[], ll size[])
{
    while(Arr[i]!=i)
    {
        Arr[i] = Arr[Arr[i]];
        i = Arr[i];
    }
    return i;
}

bool connected(ll a, ll b,ll Arr[], ll size[])
{

    if(root(a, Arr, size)==root(b, Arr, size))
        return true;
    else
        return false;
}
void un(ll a, ll b, ll Arr[], ll size[])
{
    int roota = root(a, Arr, size);
    int rootb = root(b, Arr, size);

    if(size[roota] < size[rootb] )
    {
        Arr[roota] = Arr[rootb];
        size[rootb] += size[roota];
    }
    else
    {
        Arr[rootb] = Arr[roota];
        size[roota] += size[rootb];
    }
}
int main()
{
    ll n;
    cin>>n;
    while(n--)
    {
        ll c;
        cin>>c;
        string blank;
        getline(cin,blank);
        ll Arr[c+1];
        ll size[c+1];
        for(int i=0; i<c+1; i++)
        {
            Arr[i]=i;
            size[i] = 1;
        }
        string s;
        ll cans =0, wans =0;
        while(1)
        {
        	if(!getline(cin,s) || s.empty())
        		break;
            char x;
            int e , f;
            sscanf(s.c_str(),"%c %d %d",&x,&e,&f);
            if(x=='c')
                un(e,f,Arr,size);
            else
            {
                bool z = connected(e,f, Arr, size); 
                if(z==true)
                    cans++;
                else
                    wans++;           
            	
            }
                    
        }
        
        cout<<cans<<","<<wans<<endl;
        if(n!=0)
            cout<<endl;

    }

}
