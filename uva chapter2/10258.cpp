#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{   
          int n;
          cin>>n;
          string blank;
          getline(cin,blank);
          getline(cin,blank);
          while(n--)
          {
                
                ll present[101]={0};
                ll a[101][10];
                ll penalty;
                vector<pair<int,pair<int,int> > > v;
                for(int i=1; i<101; i++)
                {
                    for(int j=1; j<10; j++)
                        a[i][j]=0;
                }

                string s;
                while(getline(cin,s)  )
                {
                	if(s.empty())
                		break;
                    int i,j,c;
                    char x;
                    sscanf(s.c_str(),"%d %d %d %c",&i,&j,&c,&x);

                    present[i] = 1;
                    if(x=='C' && a[i][j]<=0)
                        a[i][j] = (-1)*a[i][j] + c;
                    else if(x=='I' && a[i][j]<=0)
                        a[i][j] += (-1)*20;
                }

                for(int i=1; i<101; i++)
                {
                    penalty=0;
                    int q =0;
                    if(present[i]==1)
                    {
                        for(int j=1; j<=9; j++)
                        {
                            if(a[i][j] > 0)
                            {
                                q++;
                                penalty+=a[i][j];
                            }
                        }
                       
                        v.push_back(make_pair(10-q, make_pair(penalty,i) ) );
                    }
                }
                sort(v.begin(), v.end());
                //reverse(v.begin(), v.end()); 
                
               ll size = v.size();
                for(int i=0; i<size; i++)
                {
                    cout<<v[i].second.second<<" "<<10-v[i].first<<" "<<v[i].second.first<<endl;
                }   

                if(n!=0)
                    cout<<endl;
         }  
}
