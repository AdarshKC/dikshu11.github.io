#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n,d,r;
    while(cin>>n>>d>>r)
    {
        if(n==0 && d==0 && r==0)
            break;

        int m[n], e[n];

        for(int i=0; i<n; i++)
            cin>>m[i];
        for(int i=0; i<n; i++)
            cin>>e[i];

        sort(m, m+n);
        sort(e, e+n);

        ll cost = 0;
        int i = 0;
        while(i<n)
        {
            ll x = m[i]+e[n-1-i];
            if(x>d)
                cost+= (x-d)*r;

            i++;
        }
        cout<<cost<<endl;
    }
}
