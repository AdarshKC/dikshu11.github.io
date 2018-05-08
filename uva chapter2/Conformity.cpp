#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    while(cin>>t)
    {
    	if(t==0)
    		break;
	/*key is vector of courses number
	Value is number of students taking 
	that course*/
        map< vector<int>, int> m;
        while(t--)
        {
        	vector<int> a(5);
        	for(int i=0; i<5; i++)
        		cin>>a[i];
		/*Vector needs to be sorted 
		so that permuation of same 
		course dont enter in map*/       	
		sort(a.begin(), a.end());
        	m[a]++;
        }
        int ans =0, result =0;
        for(auto it= m.begin(); it!=m.end(); it++)
        {
	  /*Find number of students
	    taking most popular course*/
          if(it->second > ans)
	  {
		ans = it->second;
		result =it->second;
	  }
          else if(it->second == ans)
		result+=it->second;
        }

	cout<<result<<endl;
 
 
   }
}
