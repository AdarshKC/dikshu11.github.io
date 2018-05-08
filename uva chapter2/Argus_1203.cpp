#include<bits/stdc++.h>
#define ll long long int
#define p pair< pair<int,int> , int>
using namespace std;
int main()
{
    string s;
    /*Define a min priority queue of p
    where p.first.first stores time, 
    p.first.second stores query number
    p.second stores period*/
    priority_queue<p, vector<p>, greater<p> > q;
    while(cin>>s && s!="#")
    {
        int a,b;
        cin>>a>>b;
	/*Add p to queue*/
        q.push(make_pair( make_pair(b,a), b) );
    }
    int k;
    cin>>k;
    int i=0;
    while(i<k)
    {
       /*Print first k query
	pop the top element, 
	Add the next element ie. 
       p.first.first wil be current time + period*/
       p pair = q.top();
       int a = pair.first.second;
       int b = pair.first.first;
       int c = pair.second;
        q.push(make_pair( make_pair(b+c,a), c) );
       cout<<a<<endl;
       q.pop();
      i++;
    }

}
