/* The Fibonacci numbers are the numbers in the following integer sequence (Fn):
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...
such as F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1.

Given a prod (for product), we search two Fibonacci numbers F(n) and F(n+1) verifying F(n) * F(n+1) = prod.

Function productFib takes an integer (prod) and returns an array: {F(n), F(n+1), 1} if F(n) * F(n+1) = prod.

If don't find two consecutive F(m) verifying F(m) * F(m+1) = prod productFib will return {F(n), F(n+1), 0} 
F(m) being the smallest one such as F(m) * F(m+1) > prod.
*/

typedef unsigned long long ull;

unsigned long long* productFib(ull prod)
{
  static ull fibs[3];
  fibs[0] = 0, fibs[1] = 1;
  while (fibs[0] * fibs[1] < prod) {
      fibs[1] = fibs[0] + fibs[1];
      fibs[0] = fibs[1] - fibs[0];
  }

  fibs[2] = (fibs[0] * fibs[1] == prod) ? 1 : 0;
  return fibs;
}
