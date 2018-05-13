#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{   
    int n, p;
    while(1)
    {
        cin>>n>>p;
        if(p==0 && n==0)
            break;

        ll s = sqrt(p);
        if(s==sqrt(p) && p%2==1)
                s = sqrt(p);
        else if(s%2==0)
            s++;
        else if(s%2==1)
            s+=2;

        ll line = n/2+1+ s/2;
        ll col = n/2+ 1 + s/2;
        
        ll x = s*s;

        if(x-p <= s-1)
        {
            line -= x-p;
        }
        else if(x-p <= (s-1)*2 )
        {
            line -= (s-1);
            int z = x-(s-1);
            int y = z-p;
            col -= y;
        }
        else if(x-p <= (s-1)*3)
        {
            int z = x -(s-1)*2;
            col -=(s-1);
            line -=(s-1);
            int y = z-p;
            line += y;

        }
        else
        {
            int z = x -(s-1)*3;
            col -=(s-1);
            int y = z-p;
            col += y;
        }
        cout<<"Line = "<<line<<", column = "<<col<<"."<<endl;
    }
}
