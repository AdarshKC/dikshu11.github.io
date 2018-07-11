/*
Ethan Searches for a String
If an occurrence of A exists within B starting at some position B_j,
then Ethan’s algorithm will fail to find that occurrence if and only if
it reaches Step 2 with i > 1 and A_i = B_j = A_1. This, in turn, 
will occur if and only if a length-k prefix of A exists within 
B ending at position B_j, such that k > 1. Therefore, 
if there’s an index k such that A_k = A_1 and k > 1, 
then we can construct a string B of length |A|+k-1 by taking 
A’s length-(k-1) prefix followed by a full copy of A, and 
Ethan’s algorithm will fail to find the occurrence of A 
which starts at position B_k. For example, if A = “ABACUS”, 
then we can choose k = 3 to yield the string B = “ABABACUS”. 
If there’s no such index k, then it’s impossible for 
Ethan’s algorithm to incorrectly return false.
However, choosing any such index k is insufficient to guarantee that 
Ethan’s algorithm will return false, as if there’s another occurrence of A within B 
(in particular, starting at position B_1), then his algorithm will still find that 
one and correctly return true. For example, if A = “FBFBF”, then choosing k = 3 
would yield the string B = “FBFBFBF”, which is no good. One possibility is to try 
each valid index k, and choose one which results in the resulting B string not containing 
A as a prefix, which can be done in O(N^2) time. The time complexity may also be improved 
to O(N) by observing that, if the earliest valid index k doesn’t work out, then no later 
ones will either, due to A necessarily being “periodic” ― made up entirely of two or more 
copies of its length-(k-1) prefix (with the last copy possibly being incomplete). 
In the above example, “FBFBF” is made up entirely of copies of “FB”, 
so neither k = 3 nor k = 5 will work out.
*/

#include <bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
#define pb push_back
#define mp(i,j) make_pair(i,j)
#define fi first
#define se second
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio (false) ; 
    cin.tie(0) ; cout.tie(0) ;

	ll t;
	cin>>t;
	ll num = 0;
	while(t--)
	{
		num++;
		string s;
		cin>>s;
		
		ll n = s.length();
		ll ind = -1;
		char x = s[0];
	
		fr(i,n-1)
		{
			if(s[i]==x )
			{
				ll j = i+1;
				ll start = 1;
				
				while(j<n)
				{
					if(s[j]!=s[start])
					{
						ind = i;
						break;
					}
					j++, start++;
				}
			}
		
		}
		cout<<"Case #"<<num<<": ";
		if(ind == -1 || n==1 || n==2)
			cout<<"Impossible"<<endl;
		else
		{
			for(int i=0; i<=ind; i++)
				cout<<s[i];
			for(int i=1; i<n; i++)
				cout<<s[i];
				cout<<endl;
		}
	}
}
