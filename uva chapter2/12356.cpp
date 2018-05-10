#include<bits/stdc++.h>
#define ll long long int
using namespace std;
/* Made two arrays to store 
index of right and left available
soldier. Changed them accordingly 
as line is destroyed*/
int main()

{   
   int s,b,li,ri;
   while(cin>>s>>b)
   {
        if(s==0 && b==0)
            break;
        int a[s+1] ,l[s+1], r[s+1];
        for(int i=1; i<s+1; i++)
            a[i]=1, l[i]=i-1, r[i]= i+1;

        l[1]=-1;
        r[s]= -1;
        while(b--)
        {
            cin>>li>>ri;
            if( l[li] != -1 && a[ l[li] ]==1)
                cout<<l[li]<<" ";
            else
                cout<<"*"<<" ";

            if( r[ri] != -1 && a[ r[ri] ]==1)
                cout<<r[ri]<<endl;
            else
                cout<<"*"<<endl;
                
            for(int i=li; i<=ri; i++)
            	a[i]=0;

            if(l[li]!=-1)
                r[ l[li] ] = r[ri];
            if(r[ri]!=-1)
                l[ r[ri] ] = l[li];
            if(b==0)
                cout<<"-"<<endl;
           

        }
   }
               
}
