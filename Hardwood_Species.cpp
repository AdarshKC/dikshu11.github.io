#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    string s, blank;
    /*To scan empty line after 
    number or to move to second line*/
    getline(cin, blank);
    /*To scan next blank line*/
    getline(cin,blank);
    ll i=0;
    while(t--)
    {
        double size=0;
        if(i!=0)
          cout<<endl;
        i++;

        map<string , double> m;
	//Scan strings till s.empty()==true
        while(getline(cin,s) && !s.empty())
        {
	      /*Add species in map and increase its 
		size. Increase total size of population*/
              m[s] ++;
              size++;
        }
	//Iterate to find species and population
        for(auto it= m.begin(); it!=m.end(); it++)
        {
          double per = (it->second)*(100);
          per/=size;
          cout<<it->first<<" ";
          printf("%0.4f\n",per);
        }


    }
}
