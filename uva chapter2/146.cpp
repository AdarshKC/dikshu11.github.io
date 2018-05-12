#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{   
          string s;
          while(cin>>s && s!="#")
          {
          	 int size = s.length();
          	 int flag =0;int i=1;
          	do {
          		if(flag>1)
          			break;
          		if(flag!=0)
		{	
			cout << s << endl;
			i=0;
		}
		
		flag++;
	    } while (next_permutation(s.begin(), s.end()));
	    
	    if(i)
		cout<<"No Successor"<<endl;
          }
                
}
