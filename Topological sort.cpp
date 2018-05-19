/*Given a Directed and Acyclic Graph having N vertices and M edges,
print topological sorting of the vertices.
Input:
First line consists of two space separated integers denoting N and M.
Each of the following M lines consists of two space separated integers
X and Y denoting there is an from X directed towards Y.
Output:
Print N space separated integers denoting the topological sort, 
if there are multiple ordering print the lexicographically smallest one.*/


//Solution:

#include<bits/stdc++.h>
using namespace std;
stack<int> s;
 vector<int> v[11];
 int n,m;
 bool visited[11]= {false};
 
void dfs(int i )
{
    visited[i] = true;
    int size = v[i].size();
    for(int k=size-1; k>=0; k--)
    {
        if(!visited[ v[i][k] ])
        {
            visited[v[i][k]]= true;
            dfs(v[i][k]);
        }
    }
    s.push(i);
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    
    for(int i=1; i<=n; i++)
    {
        sort(v[i].begin(), v[i].end());
       // reverse(v[i].begin(), v[i].end());
    }
    for(int i=n; i>=1; i--)
    {
        if(visited[i]==false)
            dfs(i);
    }
    while(!s.empty())
    {
        int x = s.top();
        s.pop();
        cout<<x<<" ";
    }
}
