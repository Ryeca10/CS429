/*
 * CS:APP Data Lab
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */


#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
	/* Team name: Replace with either:
	Your login ID if working as a one person team
	or, ID1+ID2 where ID1 is the login ID of the first team member
	and ID2 is the login ID of the second team member */
	"gandalf",
	/* Student name 1: Replace with the full name of first team member */
	"Raeeca Narimani",
	/* Login ID 1: Replace with the login ID of first team member */
	"gandalf",

	/* The following should only be changed if there are two team members */
	/* Student name 2: Full name of the second team member */
	"",
	/* Login ID 2: Login ID of the second team member */
	""
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {

	// mathematically results a negated-and
	int negAnd = ~x | ~y;
	// another negation to get "and"
	int negnegAnd = ~negAnd;

	return negnegAnd;
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {

  // all 0-0 and 0-1 prositions will be assigned 1, but 1-1 positions assigned 0
  int nand = ~(x & y);
  // all 1-in-x and 0-in-y positions are assigned 1, the rest assigned 0
  int nandAndx = nand & x;
  // all 0-in-x and 1-in-y positions are assigned 1, the rest assigned 0
  int nandAndy = nand & y;
  int result = ~(~nandAndx & ~nandAndy);

  return result;

}
/*
 *
 isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {

	// is non-zero if values are different, zero if values are equal
	int xor = x ^ y;
	// a reverse to xor
	int result = !xor;

	return result;
}
/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8

 *   Rating: 2
 */
int evenBits(void) {

        // first even bit assigned 1
	int one = 1;
        // first 2 even bits assigned 1
	int two5 = (one << 2) + one;
        // first 4 even bits assigned 1
	int four5 = (two5 << 4) + two5;
        // first 8 even bits assigned 1
	int sixteen5 = (four5 << 8) + four5;
        // all 16 even bits assigned 1
        int thirtytwo5 = (sixteen5 << 16) + sixteen5;

	return thirtytwo5;
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {

    int z = 0;
	z = ~z;
    int sx = x >> 31;
    // getting rid of n bits to check if we are left with -1
    int val = x >> (n + z);
    // if after loosing first n bits we are left with -1
    int fits = !(sx ^ val);

    return fits;
}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {

	int z = 0;
        int mask;
	z = ~z;
	
    // reverse mask for all bits before highbit
    int m1 = z << highbit;
    // reverse mask for all bits until lowbit incluse
    int m2 = ~ (z << lowbit);
    // reverse mask for the highbit
    int m3 = ~ (1 << highbit);
    // reverse mask for all bits until highbit inclusive
    m1 = m1 & m3;
    // mask for all bits by negating the reverse mask
    mask = ~ (m1 | m2);

    return mask;
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {

   int result;
   // compares a number with the negative of that number
   // if value is1 has a zero at MSB, x is 0 because (0 or (-0)) has a zero at MSB
   // whereas (non-zero or (-non-zero)) has 1
   int is1 = x | (~x + 1);
   // gets the last bit of comparison
   is1 = is1 >> 31;
   // returns y if x non-zero, returns z otherwise
   result = (is1 & y)|(~is1 & z);

   return result;
}
/*
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
        
        int z = 0;
            z = ~z;
        // creates hex value 0xff
        int ff = (1 << 8) + z;
        // places the first byte as the last byte
	int byte12 = x << 24;
        // shifts so get the second byte, masks to get the second byte, 
        // and shifts again to places the second byte to the third byte location
	int byte34 = ((x >> 8) & ff) << 16;
        // shifts to get third byte, masks to get the fird byte, and shifts to places the third
        // byte into second byte location
	int byte56 = ((x >> 16) & ff) << 8;
        // shifts and masks to get the last byte and places it into first byte location
	int byte78 = (x >> 24) & ff;

        // places all the bytes into new arrangement
	int result = byte12 | byte34 | byte56 | byte78;

	return result;
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {

    // the following two commands determine if a value is zero or nonzero
    // by making a comparison of the MSB and shifting it to get -1 or 0
    int x_or_mx = x | (~x + 1);
    int bangMSB = x_or_mx >> 31;
        // adds 1 to -1 to get 0 for non-zero values, 
        // adds 1 to 0 to get 1 for 0 values
        bangMSB = bangMSB + 1;

   return bangMSB;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    //this funtion calculates the hamming weith of a value x to get how many 1 bits it has
   

    int mask5, mask3, mask0f, mask00ff, mask0000ffff;
    int a1, a2, a1Adda2, b1, b2, b1Addb2, c1, c2, c1Addc2, d1, d2, d1Addd2, e1, e2, e1Adde2;
    // The following 3 lines make a mask of 0x55555555
    mask5 = 85;
    mask5 = (mask5 << 8) + mask5;
    mask5 = (mask5 << 16) + mask5;
    // masks to get everyother bit of x
    a1 = x & mask5;
    // masks to get the remaining bits of x
    a2 = (x >> 1) & mask5;
    // adds to get the sum of the 1s pushed to left
    a1Adda2 = a1 + a2;

    
     // The following 3 lines make a mask of all 0x33333333
    mask3 = 51;
    mask3 = (mask3 << 8) + mask3;
    mask3 = (mask3 << 16) + mask3;
    // masks to get last two bit of every 4 bits of the previous sum
    b1 = a1Adda2 & mask3;
    // masks to get first two bits of every 4 bits of the previous sum
    b2 = (a1Adda2 >> 2) & mask3;
    // adds to get the ones added and pushed to left
    b1Addb2 = b1 + b2;
    

    // The following 3 lines make a mask of 0x0f0f0f0f
    mask0f = 15;
    mask0f = (mask0f << 8) + mask0f;
    mask0f = (mask0f << 16) + mask0f;
    c1 = b1Addb2 & mask0f;
    c2 = (b1Addb2 >> 4) & mask0f;
    c1Addc2 = c1 + c2;
    
    
     // The following 2 lines make a mask of 0x00ff00ff
    mask00ff = 255;
    mask00ff = (mask00ff << 16) + mask00ff;
    // masks to get every other 4 bits
    d1 = c1Addc2 & mask00ff;
    // masks to get the remaining 4 bits
    d2 = (c1Addc2 >> 8) & mask00ff;
    // adds to get the ones added and pushed to left
    d1Addd2 = d1 + d2;

    
     // The following 2 lines make a mask of 0x0000ffff
    mask0000ffff = 255;
    mask0000ffff = (mask0000ffff << 8) + mask0000ffff;
    // masks to get the first 16 bits
    e1 = d1Addd2 & mask0000ffff;
    // masks to get the last 16 bits
    e2 = (d1Addd2 >> 16) & mask0000ffff;
    // adds to get the ones added and pushed to left
    e1Adde2 = e1 + e2;
    
    return e1Adde2;
    
}
/*
 * isZero - returns 1 if x == 0, and 0 otherwise
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {

        // creates a 0 out of a non-zero value, and a 1 out of a zero value
        int iz = !x;
	return iz;
}
/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNegative(int x) {
  
        // gets the MSB which is a 1 for negative and 0 for non-negative values
	int msb = ( x >> 31) & 1;

	return msb;
}
/*
 * multFiveEights - multiplies by 5/8 rounding toward 0.
 *   Examples: multFiveEights(77) = 48
 *             multFiveEights(-22) = -13
 *   You can assume |x| < (1 << 29)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEights(int x) {

        // calculates x/2 + x/8 = 5x/8
        int div = (x >> 1) + (x >> 3);
        // gets the remainder of a positive number divided by 8
	int rem = x & 7;
        // figures out if the number is negative AND not-divisible by 8
	int non0AndNeg = (!!rem) & (x >> 31);
        // figures out if the remainder is 7 or 5 by getting the 3rd bit of the remainder
	int fiveOrSeven = rem & (rem >> 2);
        // adds the divition results with the previous glitches 
	int result = div + non0AndNeg + fiveOrSeven;
 	return result;
}
/*
 * sum3 - x+y+z using only a single '+'
 *   Example: sum3(3, 4, 5) = 12
 *   Legal ops: ! ~ & ^ | << >>
 *   Max ops: 16
 *   Rating: 3
 */
/* A helper routine to perform the addition.  Don't change this code */
static int sum(int x, int y) {
  return x+y;
}
int sum3(int x, int y, int z) {
  int word1 = 0;
  int word2 = 0;
  /**************************************************************
     Fill in code below that computes values for word1 and word2
     without using any '+' operations
  ***************************************************************/
  /**************************************************************
     Don't change anything below here
  ***************************************************************/
   
   // gets all 1s resulted from 0-1 and 1-0 bits
   word1 = (x ^ y) ^ z;
   // gets all 1s resulted by two-by-two comparison of the values which create 10
   word2 = (x & y) | (x & z) | (y & z);
   // puts 10s into righ locations
   word2 = word2 << 1;
    
    return sum(word1,word2);
}
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
    
    int sx = x >> 31;
    int sy = y >> 31;
    int xplusyOverflw = (x + y) >> 31;
    
    // figures if there is overflow of negative values added
    int negOverflw = (sx & sy & (~xplusyOverflw)) & 1 ;
    // figures if there is overflow for positive values added
    int posOverflw = ((~sx) & (~sy) & xplusyOverflw) & 1;
    
    // checks if no overflow is happening
    int addokay = (!negOverflw & !posOverflw) ;
    
    return addokay;
}
/*
 * isLess - if x < y  then return 1, else return 0
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
  
    int sx = (x >> 31) & 1;
    int sy = (y >> 31) & 1;
    
    // gets -y
    int minusy = ~y + 1;
    // gets x-y
    int xminusy = x + minusy;
    
    // checks if x-y results a negative value
    int xminusySign = (xminusy >> 31) & 1;
 
    // checks if a positive overflow has happened from x-y
    // x > 0 , y < 0 , x > y, isLess = 0
    int posOverflw = ~sx & sy & xminusySign;
    
    // checks if x-y < 0 and there vas no positive overflow
    // checks if x < 0 and y >= 0 which would make x < y always true
    int xless = (xminusySign & !posOverflw) | (sx & ~sy);
    
    return xless;
}
                     
/*
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
                     
int abs(int x) {
    
    int sx = x >> 31;
    
    // returns -x if x is negative, and x if x is non-negative
    int absVal = (sx & (~x + 1)) | (~sx & x);
    
    return absVal;
}
/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x) {

        // gets last bit of x
	int lastbitx = (x >> 31) & 1;
        // gets last bit of -x
	int lastbitmx = ((~x + 1) >> 31) & 1;
        // if x = 0, last bits of x and -x are both 0, else non-zero will be 1
        int nonZero = lastbitx | lastbitmx;
	
	return nonZero;
}
/*
 * tc2sm - Convert from two's complement to sign-magnitude
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: tc2sm(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int tc2sm(int x) {
  
    int sx = x >> 31;
    // gets absolute value of the potentially negative x
    int abs = ~x + 1;
    // creates a 1 more MSB of the potentially negative x
    int shift1 = 1 << 31;
    // creates the sign magnitude for the potentially negative x
    int negToSign = shift1 | abs;
    // checks if x is negative or non-negative
    // returns x if non-negative, returns the created sign-magnitude otherwise
    int result = (sx & negToSign) | (~sx & x);
    
    return result;
}
