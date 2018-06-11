#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   cin>>s;
   int n = s.size();
   int flag=0;
   for(int i=0; i<n-2; i++)
   {
        if(s[i]=='A')
        {
            if(s[i+1]=='B' && s[i+2]=='C')
                flag=1;
            if(s[i+2]=='B' && s[i+1]=='C')
                flag=1;
        }
        else if(s[i]=='B')
        {
            if(s[i+1]=='A' && s[i+2]=='C')
                flag=1;
            if(s[i+2]=='A' && s[i+1]=='C')
                flag=1;
        }
        else if(s[i]=='C')
        {
            if(s[i+1]=='B' && s[i+2]=='A')
                flag=1;
            if(s[i+2]=='B' && s[i+1]=='A')
                flag=1;
        }
   }
   if(flag)
    cout<<"Yes";
    else
        cout<<"No";
    
}
