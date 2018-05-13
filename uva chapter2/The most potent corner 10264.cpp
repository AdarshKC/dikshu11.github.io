#include<bits/stdc++.h>
#define ll long long int
using namespace std;

unsigned int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while (n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

int main()
{   
        int n;
        while(cin>>n)
        {
            int p = pow(2,n);
            int w[p];
            for(int i=0; i<p; i++)
              cin>>w[i];

            vector<int> v[p];
            int potency[p] = {0};
            for(int i=0; i<p; i++)
            {
              for(int j=0; j<p; j++)
              {
                if(i!=j)
                {
                    int z = i^j;
                    if(countSetBits(z)==1)
                    {
                        v[i].push_back(j);
                        potency[i] += w[j];

                    }
                  }
              }
            }

            ll ans = -1;
            for(int i=0; i<p; i++)
            {
                ll z = 0;
                for(int j=0; j<v[i].size(); j++)
                {
                    if(potency[ v[i][j] ]>z)
                      z = potency[ v[i][j] ];
                }
                z+=potency[i];
                if(z>ans)
                  ans = z;
            }
            cout<<ans<<endl;

        } 
}
