#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool awake[28];
set<int> v[28];
void init(int n)
{
    for(int i=0; i<n; i++)
    {
        v[i].clear();
        awake[i] = false;
    }
    awake[0] = true;
    awake[1] = true;
    awake[2] = true;
}


int main()
{    
    int n;
    while(cin>>n)
    {

        init(n);
        map<char,int> ma;
        int m;
        cin>>m;
        char a, b, c;
        cin>>a>>b>>c;
        ma[a] =0;
        ma[b] =1;
        ma[c] = 2;
        int ind =3;
        for(int i=0; i<m; i++)
        {
            char x,y;
            int ix, iy;
            cin>>x>>y;
            map<char, int> :: iterator it;
            it = ma.find(x);
            if(it!= ma.end() )
                ix = it->second;
            else
            {
                ix = ind;
                ma[x] = ix;
                ind++;
            }

            it = ma.find(y);
            if(it!= ma.end() )
                iy = it->second;
            else
            {
                iy = ind;
                ma[y] = iy;
                ind++;
            }
            
            v[ix].insert(iy);
            v[iy].insert(ix);
            

        }
        int ans = 0;
        int flag =0;
        while(ans<29)
        {
        	int flag1 =0;
        	queue<int> q;
        	for(int i=3; i<n; i++)
        	{
        		if(awake[i]==false)
        		{
        			int a =0;
	        		set<int>:: iterator it;
	        		for( it = v[i].begin(); it!=v[i].end(); it++ )
	        		{
	        			if(awake[ *it ]== true)
	        				a++;
	        		} 
	        		if(a>=3)
	        			q.push(i);
	        		if(awake[i]==false)
	        			flag1 = 1;
        		}
        	}
        	
        	if(flag1 ==0)
        	{	
        		cout<<"WAKE UP IN, "<<ans<<", YEARS"<<endl;
        		flag = 1;
        		break;
        	}
        	while(!q.empty())
        	{
        		int z = q.front();
        		awake[z] = true;
        		q.pop();
        	}
        	ans++;
        }
        if(flag==0)
	cout<<"THIS BRAIN NEVER WAKES UP"<<endl;


    }
}
