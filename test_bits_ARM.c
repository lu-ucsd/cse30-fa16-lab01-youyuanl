/* Testing Code */

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include "bits_ARM.h"

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

int test_bitAnd_ARM(int x, int y) {
  return x & y;
}

int test_getByte_ARM(int x, int n) {
  if (n == 0)
    return x & 0xff;
  else if (n == 1)
    return (x >> 8) & 0xff;
  else if (n == 2)
    return (x >> 16) & 0xff;
  else
    return (x >> 24) & 0xff;
}

int test_logicalShift_ARM(int x, int n) {
  return (int)((unsigned)x >> n);
}

int test_bitCount_ARM(int x) {
  int i, num, num2, count;
  for (i = count = 0; i < 31; i++) {
    num = x >> i;
    num2 = x >> (i + 1) << 1;
    if ((num - num2) == 1)
      count++;
  }
  if (x < 0)
    count++;
  return count;
}

int test_fitsBits_ARM(int x, int n) {
  int num = x << (32 - n) >> (32 - n);
  if (num == x)
    return 1;
  return 0;
}

int test_negate_ARM(int x) {
  return -x;
}

int test_isLessOrEqual(int x, int y) {
  if (x <= y)
    return 1;
  return 0;
}


int main(int argc, char *argv[]){

  //Test Cases for bitAnd_ARM

  assert(bitAnd_ARM(7,8)==test_bitAnd_ARM(7,8)); 
  assert(bitAnd_ARM(1,3)==test_bitAnd_ARM(1,3));
  assert(bitAnd_ARM(9,8)==test_bitAnd_ARM(9,8));
  assert(bitAnd_ARM(0,6)==test_bitAnd_ARM(0,6));
  assert(bitAnd_ARM(255,254)==test_bitAnd_ARM(255,254));
  printf("Passed Test Cases for bitAnd_ARM\n");

  //Test Cases for getByte_ARM

  assert(getByte_ARM(0, 3)==test_getByte_ARM(0, 3)); 
  assert(getByte_ARM(0xffffffff, 2)==test_getByte_ARM(0xffffffff, 2)); 
  assert(getByte_ARM(0xf0f0f0f0, 1)==test_getByte_ARM(0xf0f0f0f0, 1)); 
  assert(getByte_ARM(123456, 0)==test_getByte_ARM(123456, 0)); 
  assert(getByte_ARM(-123456, 3)==test_getByte_ARM(-123456, 3)); 
  printf("Passed Test Cases for getByte_ARM\n");

  //Test Cases for logicalShift_ARM

  assert(logicalShift_ARM(0, 3)==test_logicalShift_ARM(0, 3)); 
  assert(logicalShift_ARM(0xfffff, 2)==test_logicalShift_ARM(0xfffff, 2)); 
  assert(logicalShift_ARM(0xf0f0f, 1)==test_logicalShift_ARM(0xf0f0f, 1)); 
  assert(logicalShift_ARM(123456, 2)==test_logicalShift_ARM(123456, 2)); 
  assert(logicalShift_ARM(-123456, 3)==test_logicalShift_ARM(-123456, 3)); 
  printf("Passed Test Cases for logicalShift_ARM\n");

  //Test Cases for bitCount_ARM

  assert(bitCount_ARM(0)==test_bitCount_ARM(0)); 
  assert(bitCount_ARM(0xffffffff)==test_bitCount_ARM(0xffffffff)); 
  assert(bitCount_ARM(0xf0f0f0f0)==test_bitCount_ARM(0xf0f0f0f0)); 
  assert(bitCount_ARM(123456)==test_bitCount_ARM(123456)); 
  assert(bitCount_ARM(-123456)==test_bitCount_ARM(-123456)); 
  printf("Passed Test Cases for bitCount_ARM\n");

  //Test Cases for fitsBits_ARM

  assert(fitsBits_ARM(0, 3)==test_fitsBits_ARM(0, 3)); 
  assert(fitsBits_ARM(0xffffff, 6)==test_fitsBits_ARM(0xffffff, 6)); 
  assert(fitsBits_ARM(0xf0f0f0, 7)==test_fitsBits_ARM(0xf0f0f0, 7)); 
  assert(fitsBits_ARM(123456, 4)==test_fitsBits_ARM(123456, 4)); 
  assert(fitsBits_ARM(-123456, 3)==test_fitsBits_ARM(-123456, 3)); 
  printf("Passed Test Cases for fitsBIts_ARM\n");

  //Test Cases for negate_ARM

  assert(negate_ARM(0)==test_negate_ARM(0)); 
  assert(negate_ARM(0xffffffff)==test_negate_ARM(0xffffffff)); 
  assert(negate_ARM(0xf0f0f0f0)==test_negate_ARM(0xf0f0f0f0)); 
  assert(negate_ARM(123456)==test_negate_ARM(123456)); 
  assert(negate_ARM(-123456)==test_negate_ARM(-123456)); 
  printf("Passed Test Cases for negate_ARM\n");

  //Test Cases for isLessOrEqual_ARM

  assert(isLessOrEqual_ARM(-3, 2)==test_isLessOrEqual(-3, 2));
  assert(isLessOrEqual_ARM(-3, 0)==test_isLessOrEqual(-3, 0));
  assert(isLessOrEqual_ARM(0, 2)==test_isLessOrEqual(0, 2));
  assert(isLessOrEqual_ARM(2, 2)==test_isLessOrEqual(2, 2));
  assert(isLessOrEqual_ARM(2, -3)==test_isLessOrEqual(2, -3));
  printf("Passed Test Cases for isLessOrEqual_ARM\n");

  return 0;
}
