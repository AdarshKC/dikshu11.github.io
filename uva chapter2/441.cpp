#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() 
{
    ll t, i=0;
    while(cin>>t && t)
    {
        if(i!=0)
            cout<<endl;

        i++;

        vector<int> v(t);
        for(int k=0; k<t; k++)
            cin>>v[k];

        for(int k=0; k<t-5; k++)
        {
            for(int j=k+1; j<t-4; j++)
            {
                for(int l = j+1; l<t-3; l++)
                {
                    for(int m = l+1; m<t-2; m++)
                    {
                        for(int n=m+1; n<t-1; n++)
                        {
                            for(int o= n+1; o<t; o++)
                            {
                                cout<<v[k]<<" "<<v[j]<<" "<<v[l]<<" "<<v[m]<<" "<<v[n]<<" "<<v[o]<<endl;
                            }
                        }
                    }
                }
            }
        }
        
    }
}

