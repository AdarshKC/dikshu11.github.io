#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{   
        int n;
        while(  cin>>n && n)
        {
            stack<int> s,sh;
            int a[n];
            while(cin>>a[0])
            {
                if(a[0]==0)
                {
                    cout<<endl;
                    break;
                }
                for(int i=n; i>0; i--)
                   s.push(i);
                for(int i=1; i<n; i++)
                    cin>>a[i];
            
                bool m= true;
                int i=0;
                while(i<n )
                {
                	if(m==false)
                		break;
                    if(!s.empty() && a[i]==s.top() )
                    {
                        s.pop();
                    }
                    else if(!sh.empty() && a[i]== sh.top())
                    {
                        sh.pop();
                    }
                    else if(s.empty() && !sh.empty() && a[i] != sh.top() )
            	m = false;
                    else
                    {
                        while(1 )
                        {
                            if(s.empty() )
                            {
                                 m = false;
                                break;
                               
                            }
                            if(s.top() == a[i] )
                            {
                                s.pop();
                                break;
                            }
                            else
                            {
                                int x = s.top();
                                s.pop();
                                sh.push(x);
                            }
                        }
                    }
                    i++;
                    
                    
                }
                
                if(m==true &&i==n )
                    cout<<"Yes"<<endl;
                else
                    cout<<"No"<<endl;
            }

        } 
}
