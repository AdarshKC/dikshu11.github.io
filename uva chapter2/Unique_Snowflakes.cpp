#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
	/*key stores value of element in
	array. Value stores index of last
        occurance of key in array.*/
        map<int, int > m;
	/*mini stores index of element 
	after which no element duplicate is
	present*/
        int mini =0;
	/* ans stores max length*/ 
        ll ans =0;
        ll a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            map<int,int>::iterator it;

            it = m.find(a[i]);
	    /*if a[i] was not present earlier
	    add into map. Else if present, if earlier 
	    index is less than mini, update index(since 
	    it comes for first time after mini) else
	    update ans,mini and m[a[i]]  */
            if(it==m.end() )
              m[a[i]]=i;
            else
            {
              ll x = m[a[i]];
              if(x<mini)
                m[a[i]]=i;
              else
              {
                if(i-mini> ans)
                  ans = i-mini;
                mini = x+1;
                m[a[i]]= i;
              }
            }       
        }
        if(n-mini>ans)
	ans = n-mini;
        cout<<ans<<endl;
    }

}
