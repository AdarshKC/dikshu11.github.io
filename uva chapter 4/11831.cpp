#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() 
{
    map<char,char> ml, mr;
    ml['N'] = 'O';
    ml['L'] = 'N';
    ml['S'] = 'L';
    ml['O'] = 'S';

    mr['N'] = 'L';
    mr['S'] = 'O';
    mr['L'] = 'S';
    mr['O'] = 'N';

    ll n,m,s;
    while(cin>>n>>m>>s)
    {
        if(n==0 && m==0 && s==0)
            break;

        char a[n][m];
        ll sx, sy;
        char o;

        for(ll i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='N' || a[i][j]=='S' || a[i][j]=='L' ||a[i][j]=='O' )
                    o = a[i][j], sx=i,sy=j, a[i][j]='.';
            }
        }

        ll ans =0;
        while(s--)
        {
            char x;
            cin>>x;
            
           //  cout<<sx<<" "<<sy<<" "<<ans<<" "<<o<<" "<<x<<endl;
            if(x=='D')
                o = mr[o];
            else if(x=='E')
                o = ml[o];
            else
            {
                if(o=='N')
                {
                    if(sx-1>=0)
                    {
                        if(a[sx-1][sy]=='*')
                        {
                            ans++;
                            sx--;
                            a[sx][sy]='.';
                        }
                        else if(a[sx-1][sy]=='.')
                            sx--;
                    }
                }
                else if(o=='S')
                {
                    if(sx+1<n)
                    {
                        if(a[sx+1][sy]=='*')
                        {
                            ans++;
                            sx++;
                            a[sx][sy]='.';
                        }
                        else if(a[sx+1][sy]=='.')
                            sx++;
                    }
                }
                else if(o=='L')
                {
                    if(sy+1<m)
                    {
                        if(a[sx][sy+1]=='*')
                        {
                            ans++;
                            sy++;
                            a[sx][sy]='.';
                        }
                        else if(a[sx][sy+1]=='.')
                            sy++;
                    }
                }
                else if(o=='O')
                {
                    if(sy-1>=0)
                    {
                        if(a[sx][sy-1]=='*')
                        {
                            ans++;
                            sy--;
                            a[sx][sy]='.';
                        }
                        else if(a[sx][sy-1]=='.')
                            sy--;
                    }
                }
            }
            //cout<<sx<<" "<<sy<<" "<<ans<<" "<<o<<endl;
        }

        cout<<ans<<endl;
    }


      
}      

