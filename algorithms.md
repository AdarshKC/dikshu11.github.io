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
   
   
      
       
   
    
    
       


             
