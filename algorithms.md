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
      
       
   
    
    
       


             
