#include <math.h> //included a space between #include and <math.h>

#include "kaprekarUtils.h"

/**
 * <p>This function tests whether the given input <code>n</code>
 * is a Kaprekar Number or not.  A Kaprekar Number is a non-negative
 * integer n whose square can be split into two positive integers 
 * whose sum is equal to the original number.  For the purposes of 
 * this method, we restrict our consideration to base-10 representations.</p>
 * 
 * For example, 45 is a Kaprekar number, because 
 *   45<sup>2</sup> = 2025 
 * and 
 *   20 + 25 = 45. 
 * 
 * <p>See Wikipedia's  
 * <a href="https://en.wikipedia.org/wiki/Kaprekar_number">Kaprekar Number</a>
 * article for more information.</p>
 * 
 * @param n
 * @return <code>true</code> if <code>n</code> is a Kaprekar Number, 
 * <code>false</code> otherwise.
 */
int isKaprekar(int n) {

  if(n < 1) {
    return 0; //can't be false, no boolean operators in c
  }

  int i;
  long square = (long) pow(n,2); //in order to raise something to a power, use pow() function
  int numDigits = (int) log10(square) + 1; //change n to square 
  long modulus = 1; //can't be zero because then you'd divide by zero
  long first, second;
  for(i=1; i<=numDigits; i++) {
    modulus *= 10; //modulus was spelled "modulous"
    first = square / modulus;
    second = square % modulus;
    if(first >= 0 &&    //change first to second, change > to >=,and include second > 0 since you don't want negative values 
       first + second == n && second > 0) {
      return 1;
    }
  }
  return 0;
  
}
