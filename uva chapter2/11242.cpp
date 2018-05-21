#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() 
{
    ll f, r;
    while(cin>>f && f)
    {
    	
        cin>>r;
        double front[f], rear[r];

        for(int i=0; i<f; i++)
            cin>>front[i];

        for(int i=0; i<r; i++)
            cin>>rear[i];

        vector<double> v;

        for(int i=0; i<f; i++)
        {
            for(int j=0; j<r; j++)
            {
                double z = rear[j]/front[i];
                v.push_back(z);
            }
        }
        sort(v.begin() , v.end() );
        double max = -1;
        int size = v.size();
        for(int i=0; i<size-1; i++)
        {
            if(v[i+1]/v[i] > max)
                max = v[i+1]/v[i];
        }
        printf("%0.2f\n",max);
    }
}

