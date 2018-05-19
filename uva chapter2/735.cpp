#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int x;
	set<int> s;
	s.insert(0);
	for(int i=1; i<=20; i++)
	{
		s.insert(i);
		s.insert(2*i);
		s.insert(3*i);
	}
	s.insert(50);
	
	vector<int> v;
	set<int> :: iterator it;
	for(it = s.begin(); it!=s.end(); it++)
		v.push_back(*it);
		
	int size = v.size();
	while(cin>>x)
	{
		if(x<=0)
		{
			cout<<"END OF OUTPUT"<<endl;
			break;
		}
		int p=0;
		int c=0, c6=0, c3=0;
	    if(x<=180)
	    {
			for(int i=0; i<size; i++)
			{
				for(int j=0; j<size; j++)
				{
					for(int k=0; k<size; k++)
					{
						
						if( v[i]+v[j]+v[k]==x)
						{
						
							p++;
							if(v[i]==v[j] && v[j]==v[k])
								c++;
							else if(v[i]!=v[j] && v[j]!=v[k] && v[k]!=v[i])
								c6++;
							else
								c3++;
						}
					}
				}
			}
			
			c+= c6/6 + c3/3;
		
	    }
	
		if(p==0 )
			cout<<"THE SCORE OF "<<x<<" CANNOT BE MADE WITH THREE DARTS."<<endl;
		else
		{
			cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<x<<" IS "<<c<<"."<<endl;
			cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<x<<" IS "<<p<<"."<<endl;
		}
		for(int i=0; i<70; i++)
			cout<<"*";
			
		cout<<endl;
	}
}
