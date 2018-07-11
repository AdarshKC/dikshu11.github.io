/*
Interception
Writing out how the polynomial will be evaluated once the order of operations is reversed, 
we end up with a series of N+2 terms all exponentiated together (right-associatively):
(P_N * x) ^ ((N * P_{N-1}) * x) ^ ... ^ ((2 + P_1) * x) ^ ((1 + P_0) * x) ^ (0). 
The only way for such an expression to potentially evaluate to 0 is if the first term 
is equal to 0, as a^b ≠ 0 when a is a non-zero real number 
(unless b = -infinity, which isn't possible here). Since P_N is guaranteed to be non-zero,
 this means that the polynomial can only possibly evaluate to 0 when x = 0.
Now, when x = 0, it’s clear that each of the N+2 terms above is also equal to 0. So, we’re 
interested in evaluating the expression 0^0^...^0^0, with N+2 0’s. We can observe an 
alternating pattern based on the number of 0’s: 0^0 = 1, 0^0^0 = 0^1 = 0, 0^0^0^0 = 1, 
0^0^0^0^0 = 0, and so on. So, this expression evaluates to 0 when the number of 0’s is odd, 
and to 1 when the number of 0’s is even. It follows that the polynomial has a single 
x-intercept at x = 0 when N is odd, and no x-intercepts when N is even, independent of its coefficients.

*/
#include<bits/stdc++.h>
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

	ll t,num=0;
	cin>>t;
	while(t--)
	{
		num++;
		ll n;
		cin>>n;
		ll x;
		fr(i,n+1)
			cin>>x;
		
		
		cout<<"Case #"<<num<<": ";
		if(n%2)
			cout<<"1"<<endl<<"0.0"<<endl;
		else
			cout<<"0"<<endl;
	}
}


