#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{    
    int n,m;
    ll x,k;
    while(cin>>n>>m)
    {
        vector<ll> v[1000000+5];
        for(int i=1; i<n+1; i++)
        {
            cin>>x;
            v[x].push_back(i);
        }
        while(m--)
        {
            cin>>k>>x;
            if(v[x].size() < k)
                cout<<"0"<<endl;
            else
                cout<<v[x][k-1]<<endl;
        }
    }
}
