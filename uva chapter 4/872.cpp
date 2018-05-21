#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> v[27];
bool visited[27];
int ind[27];
char ans[27];
int flag =1;
void init()
{
    for(int i=0; i<27; i++)
    {
        v[i].clear();
        visited[i]=false;
        ind[i]=-1;
    }
    flag=1;
}

void getTopoOrder(int num, int pos)
{
    if(pos==num)
    {
        flag=0;
       for(int i=0; i<num; i++)
        {
            cout<<ans[i];
            if(i==num-1)
            	 cout<<endl;
            else
            	 cout<<" ";
        }
       
        return;
    }
    for(int i=0; i<27; i++)
    {
        if(ind[i]==0 && visited[i]==false)
        {
        	char x= char(i)+'A';
            ans[pos]= x ;
            
            int size = v[i].size();
            for(int j=0; j<size; j++)
                ind[v[i][j]]--;

            visited[i]=true;
            getTopoOrder(num,pos+1);
            visited[i]=false;
            for(int j=0; j<size; j++)
                ind[v[i][j]]++;
        }
    }
}
int main() 
{
    int t;
    cin>>t;
    string s, blank;
    getline(cin,blank);
    while(t--)
    {
        init();
        getline(cin,blank);
        getline(cin,s);
       
        int size = s.length();
        int num = 0;
        for(int k=0; k<size; k++)
        {
            if(s[k]!= char(32))
            {
                int x = s[k]-'A';
                ind[x]=0;
                num++;
            }    
        }
        
        getline(cin,s);
        
         size = s.length();
        for(int k=0; k<size; k++)
        {
            if(s[k]=='<')
            {
                int x = s[k-1]-'A';
                int y = s[k+1]-'A';
               // cout<<x<<" "<<y<<endl;
                v[x].push_back(y);
                ind[y]++;
            }    
        }
       getTopoOrder(num,0);
        if(flag!=0)
            cout<<"NO"<<endl;
        if(t!=0)
            cout<<endl;
    }
}

