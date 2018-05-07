#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n;
    while(cin>>n && n!=0)
    {
      
      priority_queue< ll, vector<ll> , greater<ll> > q;
      while(n--)
      {
        ll x;
        cin>>x;
        q.push(x);
      }
      ll cost =0;
      while(q.size()>1)
      {
        ll a = q.top();
        q.pop();
        ll b = q.top();
        q.pop();
        cost+= a+b;
        q.push(a+b);
      }
      cout<<cost<<endl;
    }

}
