#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    while(n--)
    {
        i++;
        ll b,sg,sb,x;
        cin>>b>>sg>>sb;

        multiset<ll> green, blue;

        for(int i=0; i<sg; i++)
        {
            cin>>x;
            green.insert(x);
        }
        for(int i=0; i<sb; i++)
        {
            cin>>x;
            blue.insert(x);
        }

        while(!green.empty() && !blue.empty() )
        {
            stack<ll> sblue, sgreen;
            for(int i=0; i<b; i++)
            {
                if(green.empty() || blue.empty())
            		break;
                ll bl = *(--blue.end());
                ll gr = *(--green.end() );
                green.erase(--green.end() );
                blue.erase( --blue.end() );
                if(bl>gr)
                    sblue.push(bl-gr);
                else if(gr>bl)
                    sgreen.push(gr-bl);
            } 
            while(!sblue.empty())
            {
                ll bl = sblue.top();
                sblue.pop();
                blue.insert(bl);
            } 
            while(!sgreen.empty())
            {
                ll bl = sgreen.top();
                sgreen.pop();
                green.insert(bl);
            } 
        }
        if(green.empty() && blue.empty())
                cout<<"green and blue died"<<endl;
        else if(!green.empty())
        {
            cout<<"green wins"<<endl;
            multiset<ll> ::reverse_iterator it;
            for(it = green.rbegin(); it!=green.rend(); it++)
            	cout<<*it<<endl;
        }
        else if(green.empty())
        {
        	multiset<ll> ::reverse_iterator it;
            cout<<"blue wins"<<endl;
            for(it = blue.rbegin(); it!=blue.rend(); it++)
            	cout<<*it<<endl;
        }
        
        if(n!=0)
    		cout<<endl;


    }

}
