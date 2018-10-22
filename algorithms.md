**Matrix Exponentiation** : used to calculate fibonnaci and other sequences in O(logn). 
  
  ```
      let F(n) be nth fibonacci number.
      Then F(n) = F(n-1) + F(n-2)
      In matrix representation :
         First matrix   =   Second matrix  *  Third matrix
         | F(n)   |     =    | 1     1 |    * | F(n-1) |
         | F(n-1) |     =    | 1     0 |    * | F(n-2) |
         
      Implementation:
      
      /* function that returns nth Fibonacci number */
         int fib(int n)
         {
           int F[2][2] = { {1,1} , {1,0} };
           if (n == 0)
             return 0;
           power(F, n-1);
           return F[0][0];
         }

         /* Optimized version of power() in method 4 */
         void power(int F[2][2], int n)
         {
           if( n == 0 || n == 1)
               return;
           int M[2][2] = { {1,1} , {1,0} };

           power(F, n/2);
           multiply(F, F);

           if (n%2 != 0)
              multiply(F, M);
         }

         void multiply(int F[2][2], int M[2][2])
         {
           int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
           int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
           int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
           int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

           F[0][0] = x;
           F[0][1] = y;
           F[1][0] = z;
           F[1][1] = w;
         }
      
  ```

**Sieve of Eratosthenes** : Given a number n, find  all primes smaller than or equal to n.
 * [Tutorial](https://www.geeksforgeeks.org/sieve-of-eratosthenes/)


**Manachar’s Algorithm** : It is used to find the Longest Palindromic Sub-string in any string. 
  * [Tutorial](https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/)
  * [Video](https://www.youtube.com/watch?v=nbTSfrEfo6M)
  
  ```
      /* 
      Manacher's Algorithm: return longest
      palindromic substring.*/

      string manacher(string s)
      {   
          ll len = s.length();


          string ne = "@";

          fr(i,len)
          {
              ne+= "#";
              ne+=s[i];
          }
          ne += "#$";

          ll c = 0, r=0;

          len = ne.size();

          ll p[len+1] = {0};

          fre(i,len-2)
          {
              ll imirror = 2*c-i;

              if(r>i)
                  p[i] = min(r-i, p[imirror]);

              while(ne[i+1+p[i]]==ne[i-1-p[i]])
                  p[i]++;

              if(i+p[i]>r)
                  c=i, r = i+p[i];

          }
          ll mlen = 0, cind = 0;

          fre(i,len-2)
          {
              if(p[i]>mlen)
                  mlen = p[i], cind = i;
          }
          return s.substr((cind-mlen-1)/2, mlen);

      }
  ```
  
**Kadane’s Algorithm** : Used to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.
 * [Tutorial](https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/)
 * [Video](https://www.youtube.com/watch?v=99ssGWhLPUE)
 
 **Modular arithmetic:**
 
   1. (a + b) % N = (a % N + b % N) % N.
   2. (a * b) % N =  ((a % N) * (b % N)) % N.
   3. (a + b) % N = ( a%N - b%N + N)%N.
   4. (a / b) % N = ( a%N )* ( modinverse(b)%N )%N;
   
 
   **Function to calculate (x^n)%M** 
   
   ```
   int modularExponentiation(int x,int n,int M)
    {
        int result=1;
        while(n>0)
        {
            if(power % 2 ==1)
                result=(result * x)%M;
            x=(x*x)%M;
            n=n/2;
        }
        return result;
    }
   ```
   
   **Euclidean algorithm:**
     To calculate greatest common divisor of a,b: it has a special property so that it can always be represented in the form of an equation i.e. ax + by = gcd(a,b)
    **Function to calculate x,y,gcd(a,b):**
    
      
      #include < iostream >

       int d, x, y;
       void extendedEuclid(int A, int B) {
           if(B == 0) {
               d = A;
               x = 1;
               y = 0;
           }
           else {
               extendedEuclid(B, A%B);
               int temp = x;
               x = y;
               y = temp - (A/B)*y;
           }
       }

       int main( ) {
       extendedEuclid(16, 10);
       cout << ”The GCD of 16 and 10 is ” << d << endl;
       cout << ”Coefficients x and y are ”<< x <<  “and  “ << y << endl;
       return 0;   
       }
      
      
   **Output**:

   
     The GCD of 16 and 10 is 2.
     Coefficients x and y are 2 and -3.

   
   ****A and M are coprime i.e.Ax+My = 1. In the extended Euclidean algorithm, x is the modular multiplicative inverse of A under modulo M.****
   
   
**Articulation Points and Bridges** : In a graph, a vertex is called an articulation point if removing it and all the edges associated with it results in the increase of the number of connected components in the graph. An edge in a graph between vertices say  and  is called a Bridge, if after removing it, there will be no path left between u and v.
[Tutorial](https://www.hackerearth.com/practice/notes/nj/)

[Example](https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-destructive-mind/description/) : [Solution](https://www.hackerearth.com/submission/19243370/)

Implementation:
  ```
  
  v is vector used to store adjacency list.
  
  visited is boolean array to keep track of nodes visited
  
  disc is int array to store discovered time of vertex
  
  low is int array to which stores, for every vertex v, the discovery time of 
  the earliest discovered vertex to which v or any of the vertices in the subtree
  rooted at v is having a back edge. It is initialized by INFINITY.
  
  parent is int array used to store parent of each node. it is initialised by NIL.
  
  is is boolean array to store if ith vertex is an articulation point.
  time is used to keep track of discovered time.
  
  ans is vector of pair<int ,int> used to store bridges
  
  void dfs(ll x,   ll time)
  {
      visited[x] = true;

      disc[x] = low[x] = time+1;
      ll child = 0;

      fr(i,v[x].size())
      {
          ll a = v[x][i];
          if(a==parent[x])
              continue; 
          if(visited[a])
              low[x] = min(low[x] , disc[a]);
          else
          {
              child++;
              parent[a] = x;
              dfs(a,time+1);
              low[x] = min(low[x], low[a]);

              //cout<<x<<" "<<a<<" "<<child<<" "<<parent[x]<<endl;
              if(parent[x]==-1 && child>1)
                  is[x] = true,num++;
              else if(parent[x]!=-1 && low[a]>=disc[x])
                  is[x] = true,num++;
              if(low[a]>disc[x])
                  ans.pb(mp(x,a));
          }

      }
  }
  ```
  
  ## KMP Algorithm :
  Used to find occurance of pattern in the given string. It calculates an array to store length of prefix which is suffix also.
  Implementation:
  
  ```
      /*
      b stores the string(pattern) and 
      we need to find it occurances in string a.
       */
      vector<ll> v;
      string a,b; 
      cin>>a>>b;
 
      ll n = a.length();
      ll m = b.length();
 
      /*
      Compute temporary array pre[m] to maintain
      size of suffix which is same as prefix
      */
      ll pre[m];
      ll i=1, j=0;
      pre[0] = 0;
      while(i<m)
      {
         if(b[i]==b[j])
            pre[i] = j+1, i++, j++;
         else if(b[i]!=b[j])
         {
            if(j==0)
               pre[i]=0, i++;
            else
               j = pre[j-1];
         }
 
      }
      i=0, j=0;
      /*
      Search for pattern in text.
      */
      while(i<n)
      {
         if(a[i]==b[j])
         {
            i++, j++;
            if(j==m)
            {
               v.pb(i+1-m);
               j = pre[j-1];
            }
         }
         else
         {
            if(j==0)
                  i++;
            else
               j =pre[j-1];
         }
      }
      if(v.size()==0)
         cout<<"Not Found\n";
      else
      {
         ll size = v.size();
         cout<<size<<endl;
         fr(i,size)
            cout<<v[i]<<" ";
         cout<<endl;
      }
      cout<<endl;
   }
  ```
  
  ## KMP using stl:
  
  ```
  std::size_t found = a.find(b, 0);
  while(found != std::string::npos) 
  {
    std::cout << "found!" << '\n';
    found = a.find(b, found+1);
   }
  ```
  
  ## Z Algorithm
  
  
  ```
  /*
  String c - whose occurances need to be find out in string s;
  z[i] stores the maximum length of substring startiing from ith position 
  which is prefix of a.
  We need to find how many times z[i] = c.length()
  a = c+'&' + s where & is character that is not present in either of the
  strings.
  */
  string s,c;
   cin>>c>>s;

   string a = c+"#"+ s;

   ll n = a.length();

   ll z[n+1];

   z[0] = 0;
   ll l=0,r=0,k;

   fre(i,n-1)
   {
      if(i>r)
      {
         l = r = i;
         while(r<n && a[r]==a[r-l])
            r++;
         z[i] = r-l;
         r--;
      }
      else
      {
         k = i-l;

         if(z[k]< r-i+1)
            z[i] = z[k];
         else
         {
            l =  i;
            while(r<n && a[r]==a[r-l])
               r++;
            
            z[i] = r-l;
               r--;
         }
      }
   }

   ll m = c.length(), ans=0;

   fre(i,n-1)
   {
      //cout<<a[i]<<" "<<z[i]<<endl;
      if(z[i]== m)
         ans++;
   }
   cout<<ans<<endl;
  ```
   
## Trie:

* Used to calculate length of common prefix of strings or related question.
* Used to calculate [maximum subarray XOR in a given array](https://www.geeksforgeeks.org/find-the-maximum-subarray-xor-in-a-given-array/) 
* Used to calculate [Maximum XOR Pair](https://www.youtube.com/watch?v=jCu-Pd0IjIA)


  ```

  /*  
  PROBLEM:
  Given an array of an integer of size n
  Find the max value of XOR of sum of 2 disjoint subarrays
  ie maximize sum(l1,r1)XORsum(l2,r2)
  */

  /*  
  LOGIC:
      We iterate the array in reverse order.Suppose we are at index i.We consider it to be the right end point of one of the subarrays.We then loop over j where 1<=j<=i  which is the left end point of the subarray.We consider we have inserted sum of all subarrays [l,r] where i<=l<=r<n in a trie.So we can compute the maximum xor value of ( sum[j,i] xor x ) where x is a value in trie.After iterating over all j, we insert in the trie sum of subarrays starting at index i. 
  */

  /* 
  IMPLEMENTATION
  */

  #include<bits/stdc++.h>
  #define ll long long int
  #define fr(i,n) for(ll i=0; i<n; i++)
  #define fre(i,n) for(ll i=1; i<=n; i++)
  #define pb push_back
  #define mp(i,j) make_pair(i,j)
  #define fi first
  #define se second
  #define pii pair<ll,ll>
  #define piii pair<ll,pii>
  using namespace std;

  struct trie
  {
     trie* left;
     trie* right;
  };

  trie* get()
  {
     trie* node = new trie;
     node->left = NULL;
     node->right = NULL;

     return node;
  }

  void insert(trie*& root, ll x)
  {
     if(root==NULL)
        root = get();

     trie* head = root;
     for(int i=32; i>=0; i--)
     {
        int b = (x>>i)&1;

        if(b==1)
        {
           if(head->right==NULL)
              head->right = get();
           head = head->right;
        }
        else
        {
           if(head->left==NULL)
              head->left = get();
           head = head->left;
        }
     }
  }

  ll query(trie* root, ll x)
  {
     ll cur = 0;
     for(int i=32; i>=0; i--)
     {
        int b = (x>>i)&1;

        if(b==1)
        {
           if(root->left!=NULL)
           {
              cur += pow(2,i);
              root = root->left;
           }
           else if(root->right != NULL)
              root = root->right;
           else
              return INT_MIN;
        }
        else
        {
           if(root->right!=NULL)
           {
              cur += pow(2,i);
              root = root->right;
           }
           else if(root->left!=NULL)
              root = root->left;
           else
              return INT_MIN;
        }
     }
     return cur;
  }
  int main()
  {
     ll n, su = 0;
     cin>>n;

     ll a[n+1];
     ll sum[n+1] = {0};

     fre(i,n)
     {
        cin>>a[i];
        sum[i] = sum[i-1]+a[i];
     }

     ll ans = INT_MIN;

     trie* root = NULL;
     insert(root, a[n]);


     for(ll i=n-1; i>=1; i--)
     {
        for(ll j=1; j<=i; j++)
        {
            ll q = query(root, sum[i]-sum[j-1] );
            if(q>ans)
            {
               ans = q;
            }
        }
        for(ll j=i; j<=n; j++)
        {
             ll su = sum[j]-sum[i-1];
             insert(root, su);
        }

     }
     cout<<ans<<endl;
  }
  ```
  ```
  /*
   We have a dictionary that we are going to create everytime we add a word in it and this task is denoted by "add word"    and later we try to find out the number of words in dictionary with the prefix which is denoted by "find prefix". We are given the value of n which simply means the number of tasks we perform and it is the first line. The next n lines contains tasks to performed as stated above either as "add word" or "find prefix".Note the " is just for making it clear .

  Input Format

  The first line contains a single integer n , denoting the number of operations to perform. Each line i of the n     subsequent lines contains an operation in one of the two forms defined above.
    
  */
  /*
   SOLUTION
   */
   
   #include<bits/stdc++.h>
  #define ll long long int
  #define fr(i,n) for(ll i=0; i<n; i++)
  #define fre(i,n) for(ll i=1; i<=n; i++)
  #define pb push_back
  #define mp(i,j) make_pair(i,j)
  #define fi first
  #define se second
  #define pii pair<ll,ll>
  #define piii pair<ll,pii>
  using namespace std;

  map<string, ll> ms;
  struct trie
  {
     map<char, trie* > ma; 
     ll w;
  };

  trie* get()
  {
     trie* node = new trie;

     node->w = 0;

     return node;
  }

  void insert(trie*& head, string s)
  {
     if(head== NULL)
        head = get();

     ll n =  s.length();
     trie* curr = head;

     for(ll i=0; i<n; i++)
     {
        if(curr->ma.find(s[i]) == curr->ma.end())
           curr->ma[s[i]] = get();

        
        curr = curr->ma[s[i]];
        curr->w ++;
     }


  }

  void search(trie* head, string s)
  {
     trie* curr = head;
     if(head==NULL)
     {
           cout<<"0"<<endl;
           return;
     }   
     ll n = s.length();

     for(int i=0; i<n; i++)
     {
        if(curr->ma.find(s[i]) == curr->ma.end())
        {
           cout<<"0"<<endl;
           return;
        }
        curr = curr->ma[s[i]];
     }

     cout<<curr->w<<endl;
  }
  int main()
  {
     ll n;
     cin>>n;
     string s,x;

     trie* head = NULL;

     fr(i,n)
     {
        cin>>s>>x;
        if(s=="add")
        {
           ms[x]++;
           insert(head, x);
        }
        else  
           search(head, x);

     }
  }
    
  ```

    
    
       


             
