/*
 * problems.c - Source file that will contain your solutions to this Lab.
 *              Submit a modified version of this file for grading.
 */

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */

char* login = "<gandalf>";
char* name  = "<Raeeca Narimani>";

/*
 * STEP 2: Read the following instructions carefully.

 * You will provide your solution to the this laboratory by
 * editing the collection of functions in this source file.

 * CODING RULES:

 *  Replace the "return" statement in each function with one or more
 *  lines of C code that implements the requested function. Your code
 *  must conform to the following style:

 *  int Funct(arg1, arg2, ...) {
      // brief description of how your implementation works
 *      int var1 = Expr1;
 *      ...
 *      int varM = ExprM;
 *
 *      varJ = ExprJ;
 *      ...
 *      varN = ExprN;
 *      return ExprR;
 *  }

 *  Each "Expr" is an expression using ONLY the following:
 *  1. Integer constants 0 through 255 (0xFF), inclusive. You are
 *      not allowed to use big constants such as 0xffffffff.
 *  2. Function arguments and local variables (no global variables).
 *  3. Unary integer operations ! ~
 *  4. Binary integer operations & ^ | + << >>
 *
 *  Some of the problems restrict the set of allowed operators even further.
 *  Each "Expr" may consist of multiple operators. You are not restricted to
 *  one operator per line.

 *  You are expressly forbidden to:
 *  1. Use any control constructs such as if, do, while, for, switch, etc.
 *  2. Define or use any macros.
 *  3. Define any additional functions in this file.
 *  4. Call any functions.
 *  5. Use any other operations, such as &&, ||, -, or ?:
 *  6. Use any form of casting.

 *  You may assume that your machine:
 *  1. Uses 2s complement, 32-bit representations of integers.
 *  2. Performs right shifts arithmetically.
 *  3. Has unpredictable behavior when shifting an integer by more
 *     than the word size.

 * EXAMPLES OF ACCEPTABLE CODING STYLE:
 */

  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
int pow2plus1(int x) {
  // exploit ability of shifts to compute powers of 2
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


/* NOTES:

 *   1. Each function has a maximum number of operators (! ~ & ^ | + << >>)
 *      that you are allowed to use for your implementation of the function.
 *      Note that '=' is not counted; you may use as many of these as you
 *      want without penalty.

 *   2. Develop the test harness to check your functions for correctness.

 *   3. The maximum number of ops for each function is given in the
 *      header comment for each function. If there are any
 *      inconsistencies between the maximum operations in the writeup
 *      and in this file, consider this file the authoritative source.
 */

/*
 * STEP 3: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   Use the dlc compiler to check that your solutions conform to the
 *   coding rules.
 *
 *   Remember, you are to replace the statement "return( 2 );" with
 *   suitable statements and the final statement should be a return
 *   statement that returns the computation specified.
 */


// problems.c   -- file of problems

// Create operational C programs from text descriptions.


/*
 *  Multiply by 7
 *    Example:  times_7( 3 ) = 21
 *    0 <= n && n < 2^28
 *    Legal ops:  +
 *    Max ops:  4
 *
 *    Number of X86 instructions:
 */
int times_7( int n ){

        int x1 = n + n;
        int x2 = x1 + x1;
        int x3 =  x2 + x1 + n;

	return( x3 );
}


/*
 *  ASCII Code?
 *    Example:  is_ascii( 10 ) = 1,  is_ascii( 1000 ) = 0
 *    0 <= n && n < 2^28
 *    Legal ops:  < &   !! Note < operator is OK for this problem!!
 *    Max ops:  5
 *
 *    Number of X86 instructions:
 */
int is_ascii( int n ) {

        int trueFalse = (n < 255) & (0 < n);

  	return ( trueFalse );



/*
 *  ASCII Character (upper or lower case) Code?
 *    Example:  is_character( 10 ) = 0,  is_character( 'b' ) = 1
 *    0 <= n && n < 2^28
 *    Legal ops:  < &   !! Note < operator is OK for this problem!!
 *    Max ops:  6
 *
 */
int is_character( int n ) {

	int trueFalse =  (n < 123 ) & (64 < n );

	return trueFalse;
}


/*
 *  Remainder after dividing by 8
 *    Example:  remainder_by_8( 15 ) = 7
 *              remainder_by_8( 33 ) = 1
 *    0 <= n && n < 2^28
 *    Legal ops:  &
 *    Max ops:  5
 *
 *    Number of X86 instructions:
 */


int remainder_by_8( int n ) {

  int remain = n & 3;

  return remain;
}

/*
 *  Negation
 *    Example:  negation( 25 ) = -25
 *    Example:  negation( -8 ) = 8
 *    Legal ops:  ~ +
 *    Max ops:  4
 *
 *    Number of X86 instructions:
 */
int negation( int n ) {
  
	int neg = 1 + (~n);
  
	return neg;
}


/*
 *  Bit Counting
 *    Example:  bit_count( 30 ) = 4
 *    0 <= n && n < 2^8
 *    Legal ops:  & >> +
 *    Max ops:  25
 */
int bit_count( int n ) {

        int count = 0;

        count += (n & 1);
        n = n >> 1 ;
        count += (n & 1);
        n = n >> 1;
        count += (n & 1);
        n = n >> 1;
        count += (n & 1);
        n = n >> 1;
        count += (n & 1);
        n = n >> 1;
        count += (n & 1);
        n = n >> 1;
        count += (n & 1);

        return count;

}




/*
 *  Overflow detection of 3*n -- harder problem
 *    Input is positive
 *    Example:  overflow( 10 ) = 0
 *    Example:  overlfow( 1<<30 ) = 1
 *    Legal ops:  & | >> << ~
 *    Max ops:  10
 *
 *    Number of X86 instructions:
 */



int overflow_3( int n ) {

          int ans = n + n + n;   // Do not alter this statement
          // Your solution goes below here.

          int lastBit = (ans >> 31) & 1;

          return lastBit;
}




/*
 *  Rearrange bytes
 *    Example:  reverseBytes( 0x01234567 ) = 0x67452301
 *    Legal ops:  & | >> <<
 *    Max ops:  11
 *
 *    Number of X86 instructions:
 */



int reverseBytes( unsigned int n ) {

  int x1 = n << 24 ;
  int x2 = n << 16;
      x2 = x2 >> 24;
      x2 = x2 << 16;	
  int x3 = n << 8;
      x3 = x3 >> 24;
      x3 = x3 << 8;
  int x4 = n >> 24;  
  int result = x1 | x2 | x3 | x4 ;

  return result;
}



/*
 *  Your own challenge problem
 *    Example:  function returns 0 if n/2 is even, and 2 if n/2 is odd
 *    Legal ops: &
 *    Max ops: 1
 *
 *  Ignore the "dlc" warning -- we don't know what operations are expected.
 *  "dlc" will only check for C-syntax errors.
 */




int your_challenge( int n ) {

        int checkOdd = n & 2;

        return checkOdd;
  
}


