/*
 * bit.c
 *
 *  Created on: Jan 6, 2015
 *      Author: kqchen
 */
#include <stdio.h>

int swap_num(int *num1, int* num2) {
   *num1 = *num1 ^ *num2;
   *num2 = *num1 ^ *num2;
   *num1 = *num1 ^ *num2;

   return(0);
}

void swap_t(int* x, int* y)
{
  int *temp;
  *temp = *x;
  *x = *y;
  *y = *temp;
}

void stringSwap(char** a, char** b){
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int Foo(int *x, int *y)
{
  *x = *x << 1;
  // add 4 to the y coordinate
  *y = *y + 4;
  return 1;
}

//Display integer number into binary using bitwise operator
void printBinary(unsigned int num)
{
	unsigned int size_of_uint, mask, count=0;
	size_of_uint = sizeof(num) * 8;
	mask = 1<<(size_of_uint-1);
	printf("size of the unsigned integer:%d, mask=0x%x\n", size_of_uint, mask);
#if 0
	int mask = 0x4000;
   if ((num & 0x8000) == 0)
      printf("0");
   else
      printf("1");
#endif

   while (mask != 0) {
	   count++;
      if ((num & mask) == 0)
         printf("0");
      else
         printf("1");
      mask = mask >> 1;
   }
   printf("\n count of bits =%d\n", count);
}

void count_ones(unsigned int num) {
   int count = 0;

   printf("The number: %d\n", num);

   printf("\nDecimal number in binary format :\n");
   printBinary(num);

   while (num != 0) {
      if ((num & 1) == 1) {
         break;
      } else {
         count++;
         num = num >> 1;
      }
   }
   printf("\nTrailing Zeros : %d\n", count);
}
