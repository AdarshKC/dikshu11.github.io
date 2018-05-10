#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()

{   
    int n;
    while(cin>>n)
    {
        bool present[n] = {false};
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        for(int i=1; i<n; i++)
        {
            present[ abs( a[i]-a[i-1] ) ]= true;
        }
        int flag =0;
        for(int i=1; i<n; i++)
        {
            if(present[i]==false )
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
            cout<<"Jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;
    }
               
}
