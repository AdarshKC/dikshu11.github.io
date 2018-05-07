#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n;
    map<char, int> m;
    while(cin>>n )
    {
        m['s'] = 1;
        m['q'] = 1;
        m['p'] = 1;

        stack<int> s;
        queue<int> q;
        priority_queue<int> p;

        while(n--)
        {
          int x, y;
          cin>>x>>y;
          if(x==1)
          {
            if(m['s']==1)
              s.push(y);
            if(m['q']==1)
              q.push(y);
            if(m['p']==1)
              p.push(y);
          }
          else
          {
              if(m['s']==1)
              {
              	if(!s.empty())
                 {
                 	    int a = s.top();
		                if(a!=y)
		                  m['s']=0;
		                else 
		                  s.pop();
                 }
                 else
                         m['s']=0;
              }
              if(m['q']==1)
              {
                if(!q.empty())
                 {
                 	    int a = q.front();
		                if(a!=y)
		                  m['q']=0;
		                else 
		                  q.pop();
                 }
                 else
                         m['q']=0;
              }
              if(m['p']==1)
              {
                if(!p.empty())
                 {
                 	    int a = p.top();
		                if(a!=y)
		                  m['p']=0;
		                else 
		                  p.pop();
                 }
                 else
                         m['p']=0;;
              } 

          }
        }
        if(m['s']!=1 && m['p']!=1 && m['q']!=1 )
            cout<<"impossible"<<endl;
        else if(m['s']==1 && m['p']!=1 && m['q']!=1 )
            cout<<"stack"<<endl;
        else if(m['s']!=1 && m['p']==1 && m['q']!=1 )
            cout<<"priority queue"<<endl;
        else if(m['s']!=1 && m['p']!=1 && m['q']==1 )
            cout<<"queue"<<endl;
        else
            cout<<"not sure"<<endl;

    }

}
