#include<bits/stdc++.h>
#define p pair<int,int>
#define ll long long int
using namespace std;

/* Since matrix is parse store index and
value in adjacencey list.To print transpose,
take adjacency vector of size n+1(taking 1 index
system). Vector is made of pair<int, int>
for i-th row, j-th column , and value x
store pair <i,x> in v[j] as done. */
int main()
{   
    ll m,n;
    while(cin>>m>>n)
    {
        vector<p> v[n+1];
        for(int i=1; i<=m; i++)
        {
            ll a;
            cin>>a;

            ll index[a], value[a];
            for(int j=0; j<a; j++)
                cin>>index[j];
            for(int j=0; j<a; j++)
                cin>>value[j];
            for(int j=0; j<a; j++)
                v[ index[j] ].push_back(make_pair(i,value[j] ));
        }
        cout<<n<<" "<<m<<endl;
        for(int i=1; i<=n; i++)
        {
            int x = v[i].size();
            cout<<x;
            if(x!=0)
            	cout<<" ";
            for(int k=0; k<x; k++)
            {    
            	cout<<v[i][k].first;
            	if(k!=x-1)
            		cout<<" ";
            }
            cout<<endl;
            for(int k=0; k<x; k++)
            {    
            	cout<<v[i][k].second;
            	if(k!=x-1)
            		cout<<" ";
            }  
            cout<<endl;

        }
    }
}
