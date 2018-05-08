#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    while(cin>>n && n!=0)
    {
        multiset<ll> s;
        ll cost = 0;
        while(n--)
        {
            ll a,c;
            cin>>a;
            for(int i=0; i<a; i++)
            {
               
                cin>>c;
                s.insert(c);
            }
	
            ll low = *s.begin();
            ll high = *(--s.end());
            ll size = s.size();
            s.erase(s.begin());
            s.erase(--s.end() );
            cost += high-low;
        }
        cout<<cost<<endl;
    }

}
