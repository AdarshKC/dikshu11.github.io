#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()

{   
    int n;
    scanf("%d",&n);
   
     while(n--)
    {
        
		map<char,ll> m;
        ll x;
        scanf("%lld",&x);
        while(x--)
        {
            char a;
            ll cost;
            cin>>a;
            scanf("%lld",&cost);
            m[a]=cost;
        }
        scanf("%lld",&x);
       double ans =0;
       char ch=getchar();
        while(x--)
        {
            string s;
            getline(cin, s);
            int len = s.length();
            for(int i=0; i<len; i++)
            {
                char a = s[i];
                map<char,ll> :: iterator it;
                it = m.find(a);
                if(it!=m.end())
                    ans+=it->second;
            }
        }
        ans/=100;
        printf("%0.2f$\n",ans);
    }
               
}
