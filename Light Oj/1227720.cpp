#include<bits/stdc++.h>
#define ll long long int
#define M 1000000;
using namespace std;

void create(int* a, int* s, int low, int high, int pos)
{
    if(low==high)
     {
           s[pos] = a[low];
          return;
     }  
    int mid = (high+low)/2;
    create(a,s,low,mid,2*pos+1);
    create(a,s,mid+1,high,2*pos+2);
    s[pos] = min(s[2*pos+1]  , s[2*pos+2]);
}

int query(int *s, int l, int r, int low, int high,int pos)
{
    int mid = (high+low)/2;
   if(l>high || r<low)
      return M;
   if(l<=low && r>=high)
      return s[pos];

   return min( query(s,l,r,low,mid,2*pos+1),query(s,l,r,mid+1,high,2*pos+2) );
}
int main()
{   
      
       int i=1;
       int t,l,r;
       scanf("%d",&t);
       string blank;

       while(t--)
       {
          int n,q;
          scanf("%d%d",&n,&q);
          int a[n];
          for(int i=0; i<n; i++)
            scanf("%d",&a[i]);

          int s[4*n];
          printf("Case %d:\n",i);
          i++;
          create(a,s,0,n-1,0);
          for(int i=0; i<q; i++)
          {
              scanf("%d %d",&l, & r);
              l--,r--;
             int ans = query(s,l,r,0,n-1, 0);
              printf("%d\n",ans);
          }


       }  
                
}
