/* 
 * CS:APP Data Lab 
 * 
 * Name:      Youyuan Lu
 * PID:       A92022633
 * Gighub ID: lu-ucsd
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

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

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
7. Use any data type other than int.  This implies that you
cannot use arrays, structs, or unions.


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

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
    the coding rules are less strict.  You are allowed to use looping and
    conditional control.  You are allowed to use both ints and unsigneds.
    You can use arbitrary integer and unsigned constants.

    You are expressly forbidden to:
    1. Define or use any macros.
    2. Define any additional functions in this file.
    3. Call any functions.
    4. Use any form of casting.
    5. Use any data type other than int or unsigned.  This means that you
    cannot use arrays, structs, or unions.
    6. Use any floating point data types, operations, or constants.


    NOTES:
    1. Use the dlc (data lab checker) compiler (described in the handout) to 
  check the legality of your solutions.
2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
  that you are allowed to use for your implementation of the function. 
  The max operator count is checked by dlc. Note that '=' is not 
  counted; you may use as many of these as you want without penalty.
  3. Use the gradescope autograder and your own tester to check your functions for correctness.
  4. Use the dlc program to check if your functions meet the constraints on the
  maximum number of ops and permissible operators.
  5. The maximum number of ops for each function is given in the
  header comment for each function. If there are any inconsistencies 
  between the maximum ops in the writeup and in this file, consider
  this file the authoritative source.

  /*
   * STEP 2: Modify the following functions according the coding rules.
   * 
   *   IMPORTANT. TO AVOID GRADING SURPRISES:
   *   1. Use the dlc compiler to check that your solutions conform
   *      to the coding rules.
   *   2. Use the gradescope autograder to check for logical correctness 
   */


#endif
  /* Copyright (C) 1991-2014 Free Software Foundation, Inc.
     This file is part of the GNU C Library.

     The GNU C Library is free software; you can redistribute it and/or
     modify it under the terms of the GNU Lesser General Public
     License as published by the Free Software Foundation; either
     version 2.1 of the License, or (at your option) any later version.

     The GNU C Library is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
     Lesser General Public License for more details.

     You should have received a copy of the GNU Lesser General Public
     License along with the GNU C Library; if not, see
     <http://www.gnu.org/licenses/>.  */
  /* This header is separate from features.h so that the compiler can
     include it implicitly at the start of every compilation.  It must
     not itself include <features.h> or any other header that includes
     <features.h> because the implicit include comes before any feature
     test macros that may be defined in a source file before it first
     explicitly includes a system header.  GCC knows the name of this
     header in order to preinclude it.  */
  /* glibc's intent is to support the IEC 559 math functionality, real
     and complex.  If the GCC (4.9 and later) predefined macros
     specifying compiler intent are available, use them to determine
     whether the overall intent is to support these features; otherwise,
     presume an older compiler has intent to support these features and
     define these macros by default.  */
  /* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
     Unicode 6.0.  */
  /* We do not support C11 <threads.h>.  */
  /* 
   * bitAnd - x&y using only ~ and | 
   *   Example: bitAnd(6, 5) = 4
   *   Legal ops: ~ |
   *   Max ops: 8
   *   Rating: 1
   */
  int bitAnd(int x, int y) {
    /* "not((not(x)) or (not(y)))" is the same as "x and y" */
    return ~(~x | ~y);
  }
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /* shift x right (8 * n) bits and mask it to get the result */
  return (x >> (n << 3)) & 0xff;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  /* shift x right n bits and mask it to get the result */
  int neg_n = ~n + 1;
  int bits = 32 + neg_n;
  int mask = ~(~0 << bits);
  return (x >> n) & mask;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /* continuously reduce weights to get the count */
  int temp1 = (0x55 << 8) + 0x55;
  int mask1 = (temp1 << 16) + temp1; // 1st mask
  int temp2 = (0x33 << 8) + 0x33;
  int mask2 = (temp2 << 16) + temp2; // 2nd mask
  int temp3 = (0xf << 8) + 0xf;
  int mask3 = (temp3 << 16) + temp3; // 3rd mask
  int mask4 = (0xff << 16) + 0xff;  // 4th mask
  int mask5 = (0xff << 8) + 0xff; // 5th mask
  
  int left = x & mask1;  /* reduce weights */
  int right = (x >> 1) & mask1;
  int sum = left + right;

  left = sum & mask2; /* reduce weights */
  right = (sum >> 2) & mask2;
  sum = left + right;

  left = sum & mask3; /* reduce weights */
  right = (sum >> 4) & mask3;
  sum = left + right;

  left = sum & mask4; /* reduce weights */
  right = (sum >> 8) & mask4;
  sum = left + right;

  left = sum & mask5; /* reduce weights */
  right = (sum >> 16) & mask5;
  sum = left + right;

  return sum;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  /*add 0xffffffff to x and check the number on the 33rd bit */
  int bit1 = ((x & 1) + 1) >> 1; // get the carry-out of (lsb + 1)
  int mask = ~(1 << 31);
  int bit31 = ((x >> 1) & mask) + mask;
  return (((bit31 + bit1) >> 31) & 1) ^ 1; // get the 33rd bit and flip it
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /* return 0x80000000 */
  return 1 << 31;
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
  /* check if the (33 - n) bits on the left are all 1's or all 0's */
  int mask = ~(~0 << (33 + (~n + 1)));
  int num = (x >> (n + ~0)) & mask; // get the (33 - n) bits on the left
  int test = (x >> 31) & mask;
  return !(num ^ test);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  /* shift x right n bits and add 1 if necessary */
  int r1 = x >> n;
  int r2 = (~x + 1) >> n;
  int msb = (x >> 31) & 1;
  return r1 + ((!(!(r1 + r2))) & msb); // check if 1 needs to be added
}
/* 
 * negate - return -x 
 * You may handle results that fall out of signed int range in any way that you
 * like
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /* in two's complement, -x is the same as (~x + 1) */
  return ~x + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  /* (!x + msb) is 0 if and only if x is positive */
  int msb = (x >> 31) & 1;
  return !(!x + msb);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /* check if (y - x) is non-negative */
  int diff = y + (~x + 1);
  return !(diff >> 31);
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  /* find the position of first 1 from left in binary representation of x */
  int i = 16;
  int num = (x >> i);
  int b = !(!(num));
  int d = ~b + 1;
  int lg = (d & 16);

  i = i + ~8 + 1 + (d & 16); /* half the search interval */
  num = (x >> i);
  b = !(!(num));
  d = ~b + 1;
  lg = lg + (d & 8);

  i = i + ~4 + 1 + (d & 8); /* half the search interval */
  num = (x >> i);
  b = !(!(num));
  d = ~b + 1;
  lg = lg + (d & 4);

  i = i + ~2 + 1 + (d & 4); /* half the search interval */
  num = (x >> i);
  b = !(!(num));
  d = ~b + 1;
  lg = lg + (d & 2);

  i = i + ~1 + 1 + (d & 2); /* half the search interval */
  num = (x >> i);
  b = !(!(num));
  d = ~b + 1;
  lg = lg + (d & 1);

  return lg;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  /* flip the msb of uf */
  int bit8 = !(((uf >> 23) & 0xff) ^ 0xff);
  int bit23 = uf << 9;
  if (bit8 && bit23) /* return the original argument when it's NaN */
    return uf;
  return uf ^ (1 << 31);
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  /* find the position of first 1 from left in binary reprsentation of |x|, 
   * then get the mantissa and exponent according to this position
   */
  int value = x;
  int msb = x & 0x80000000;
  unsigned result = msb;
  int mask = 0xffff0000;
  int index = 16;

  if (msb) /* get |x| */
    value = -x;

  if (value & mask) { /* half the search interval */
    mask = mask << 8;
    index = index + 8;
  } else {
    mask = mask >> 8;
    index = index - 8;
  }

  if (value & mask) { /* half the search interval */
    mask = mask << 4;
    index = index + 4;
  } else {
    mask = mask >> 4;
    index = index - 4;
  }

  if (value & mask) { /* half the search interval */
    mask = mask << 2;
    index = index + 2;
  } else {
    mask = mask >> 2;
    index = index - 2;
  }

  if (value & mask) { /* half the search interval */
    mask = mask << 1;
    index = index + 1;
  } else {
    mask = mask >> 1;
    index = index - 1;
  }

  if (value & mask) /* get the position of first 1 */
    index = index + 1;

  result = result | ((126 + index) << 23); // get the biased exponent

  value = value << (32 - index); /* get the mantissa */
  value = value >> 8;
  value = value & 0x007fffff;
  result = result | value;

  if (!x)
    result = 0;

  return result;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  /* increase the exponent by 1 if the input is proper */
  int bit8 = (uf >> 23) & 0xff;
  int bit23 = uf && 0x7fffff;
  if (bit8 == 0xfe) /* when (uf * 2) reaches infinity */
    uf = (uf & 0x80000000) | 0x7f800000; 
  else if ((bit8 ^ 0xff) && bit8) /* when (uf * 2) doesn't reach infinity */
    uf = uf + 0x800000;
  else if ((bit8 == 0) && bit23) /* when the exponent is -127 */
    uf = uf + 0x800000;
  return uf;
}
