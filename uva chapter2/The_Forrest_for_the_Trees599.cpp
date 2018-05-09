#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{   
    ll n;
    cin>>n;
    string blank;
    getline(cin,blank);
    while(n--)
    {
	/*visited array is uesd for dfs
	present array is used to find which
	alphabets are present(A-Z) in forrest
	v is vector for adjacency vector*/
        bool visited[26] = {false};
        bool present[26] = {false};
        vector<int> v[26];
        string s;
        
        while(getline(cin,s))
        {
            if(s[0]=='*')
                break;
	
            int x = s[1]-'A';
            int y = s[3]-'A';
		if(x!=y)
		{
			    v[x].push_back(y);
			    v[y].push_back(x);
		}
        }
        int tree=0, acorn =0;
        getline(cin,s);
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!=',')
            {
                int x = s[i]-'A';
                present[x] = true;
            }
        }
        for(int i=0; i<26; i++)
        {
            if(present[i]==true && visited[i]== false)
            {
                if(v[i].size()==0)
                   acorn++;
                else
                {
                    stack<int> st;
                    st.push(i);
                    visited[i]= true;
                    tree++;
                    while(!st.empty())
                    {
                        int x = st.top();
                        st.pop();
                        for(int j=0; j<v[x].size(); j++)
                        {
                            if(visited[ v[x][j] ] == false)
                            {
                                visited[ v[x][j] ] = true;
                                st.push(v[x][j]);
                            }
                        }
                    }
                }
                
            }
        }
        if(!s.empty())
	cout<<"There are "<<tree<<" tree(s) and "<<acorn<<" acorn(s)."<<endl;
        else
	cout<<"There are 0 tree(s) and 1 acorn(s)."<<endl;

    }
}
