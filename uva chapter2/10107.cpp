#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{   
          vector<ll> v;
          ll n;
          int size =0;
          while(cin>>n)
          {
                v.push_back(n);
                sort(v.begin(), v.end());
                size++;
                if(size==1)
                    cout<<v[0]<<endl;
                else if(size%2==1)
                  cout<<v[size/2 ]<<endl;
                else
                {
                    int ans =  v[size/2 -1] + v[size/2];
                    ans/=2;
                    cout<<ans<<endl;
                }
                
        }

                
}
