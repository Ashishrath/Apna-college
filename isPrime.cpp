#include <iostream>

using namespace std;

bool IsPrime(int n) {
  // Trivial case 1: small numbers
  if (n <= 1) return false;

  // Trivial case 2: even numbers
  if (n % 2 == 0) return n == 2;

  // Now, we have that n is odd and n >= 3.

  // Try to divide n by every odd number i, starting from 3
  for (int i = 3;; i += 2) {
    // We only have to try i up to the square root of n
    if (i > n / i) break;

    // Now, we have i <= n/i < n.
    // If n is divisible by i, n is not prime.
    if (n % i == 0) return false;
  }

  // n has no integer factor in the range (1, n), and thus is prime.
  return true;
}

int main()
{   
  int num;
  cout<<"Enter a number: "<<endl;
  cin>>num;
  if(IsPrime(num)) {
    cout<< num <<" is a prime number" <<endl;
  } else {
    cout<< num <<" is not a prime number" <<endl;
  }
  
  return 0;
}
