/*
 * array.c
 *
 *  Created on: Jan 6, 2015
 *      Author: kqchen
 */
#include <stdio.h>
//#include <conio.h>
#define MAX 30

int delete_dup() {
   int arr[20], i, j, k, size;

   printf("\nEnter array size : ");
   scanf("%d", &size);
   if (size > 20) {
	   printf("array size can not larger than 20, exit\n");
   	   return 0;
   }

   printf("\nAccept Numbers : ");
   for (i = 0; i < size; i++)
      scanf("%d", &arr[i]);

   printf("\nArray with Unique list  : ");
   for (i = 0; i < size; i++) {
      for (j = i + 1; j < size;) {
         if (arr[j] == arr[i]) {
            for (k = j; k < size; k++) {
               arr[k] = arr[k + 1];
            }
            size--;
         } else
            j++;
      }
   }

   for (i = 0; i < size; i++) {
      printf("%d ", arr[i]);
   }

   return (0);
}


void reverse_array_elements() {
   int size, i, arr[MAX];
   int *ptr;
   //clrscr();

   ptr = &arr[0];

   printf("\nEnter the size of array : ");
   scanf("%d", &size);

   printf("\nEnter %d integers into array: ", size);
   for (i = 0; i < size; i++) {
      scanf("%d", ptr);
      ptr++;
   }

   ptr = &arr[size - 1];

   printf("\nElements of array in reverse order are :\n");

   for (i = size - 1; i >= 0; i--) {
      printf("Element%d is %d : \n", i, *ptr);
      ptr--;
   }

   //getch();
}

int array_insertion(int* input_array, int num, int element, int location) {
   int arr[30], i;

   printf("number of elements :%d\n", num);
   if (num >= 30) {
	   printf("no more room to insert new element.\n");
   	   return 0;
   }

   for (i = 0; i < num; i++) {
      arr[i] = input_array[i];
   }

   printf("the element to be inserted :%d\n", element);

   printf("the location to be inserted: %d\n", location);

   if (location >= 30) {
	   printf("Not a valid location to insert new element.\n");
   	   return 0;
   }

   //Create space at the specified location
   for (i = num; i >= location; i--) {
      arr[i] = arr[i - 1];
   }

   num++;
   arr[location - 1] = element;

   //Print out the result of insertion
   for (i = 0; i < num; i++)
      printf("%d\n", arr[i]);

   return (0);
}


// Return the maximum value within the array
int ReturnMaxFromArray(int *array, int arrayCount)
{
	int retVal=0;
	int count, index=-1;
	//
	// To be done:
	// If we can, we should check the passed in array size
	// against the arrayAcount. If it is arrayCount exceed,
	// return -1.
	//
	for(count = 0; count < arrayCount; count++)
	{
		if (array[count] >= retVal)
		{
		  retVal = array[count];
		  index=count;
		}
	}

	if (index == -1)
	  return -1;

	return index;
}
