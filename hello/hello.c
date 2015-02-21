/*
 * hello.c
 *
 *  Created on: Dec 29, 2014
 *      Author: kqchen
 *      (1) A goto statement implements a local jump of program execution,
 *      and the longjmp() and setjmp() functions implement a nonlocal, or far, jump of program execution.
 *      However, there is a major drawback to using these functions:
 *      your program, when restored to its previously saved state,
 *      will lose its references to any dynamically allocated memory between the longjmp() and the setjmp().
 *      This means you will waste memory for every malloc() or calloc() you have implemented
 *      between your longjmp() and setjmp(), and your program will be horribly inefficient.
 *      (2) The one's complement operator in C is ~.
 *      To clear the bits of interest, the number is bitwise ANDed with the one's complement of the bit mask.
 *      To set the bits of interest,
 *      the number is bitwise "ORed" with the bit mask (the bitwise OR operator in C is |).
 *      (3) s it better to use a pointer to navigate an array of values,
 *      or is it better to use a subscripted array name?
 *      [anwser] user pointer to navigate faster.
 *      (4)  If the location the program wants to access is on disk,
 *      the page containing it must be read from disk into memory,
 *      and the PMM must be updated to reflect this action (this is called a "page fault").
 *      The problem of many page faults occurring in a short time,
 *      called "page thrashing," can drastically cut the performance of a system.
 *      (5) The volatile modifier is a directive to the compiler's optimizer that operations involving
 *      this variable should not be optimized in certain ways.
 *      There are two special cases in which use of the volatile modifier is desirable.
 *      The first case involves memory-mapped hardware (a device such as a graphics adaptor
 *      that appears to the computer's hardware as if it were part of the computer's memory),
 *      and the second involves shared memory (memory used by two or more programs running simultaneously).
 *      (6)
 *      If an operation is specified with operands of two different types,
 *      they are converted to the smallest type that can hold both values.
 *      (7)
 *      There are two situations in which to use a type cast.
 *      The first use is to change the type of an operand to an arithmetic operation
 *      so that the operation will be performed properly.
 *      The variable f1 is set to the result of dividing the integer i by the integer j.
 *      The result is 0, because integer division is used.
 *      The variable f2 is set to the result of dividing i by j as well.
 *      However, the (float) type cast causes i to be converted to a float.
 *      That in turn causes floating-point division to be used and gives the result 0.75.
 *      The second case is to cast pointer types to and from void * in order to interface with
 *      functions that expect or return void pointers. For example, the following line
 *      type casts the return value of the call to malloc() to be a pointer to a foo structure.
 *      struct foo *p = (struct foo *) malloc(sizeof(struct foo));
 *
 *      A type cast should not be used to override a const or volatile declaration.
 *      Overriding these type modifiers can cause the program to fail to run correctly.
 *      A type cast should not be used to turn a pointer to one type of structure or data type
 *      into another. In the rare events in which this action is beneficial,
 *      using a union to hold the values makes the programmer's intentions clearer.
 *
 *      (8) Is it acceptable to declare/define a variable in a C header?
 *      A global variable that must be accessed from more than one file can and should be declared
 *      in a header file. In addition, such a variable must be defined in one source file.
 *      Variables should not be defined in header files, because the header file can be included
 *      in multiple source files, which would cause multiple definitions of the variable.
 *      The ANSI C standard will allow multiple external definitions,
 *      provided that there is only one initialization.
 *      But because there's really no advantage to using this feature,
 *      it's probably best to avoid it and maintain a higher level of portability.
 *      "Global" variables that do not have to be accessed from more than one file should be
 *      declared static and should not appear in a header file.
 *
 *      (9)
 *      Declaring a variable means describing its type to the compiler but not allocating any space for it.
 *      Defining a variable means declaring it and also allocating space to hold the variable.
 *      You can also initialize a variable at the time it is defined.
 *
 *      (10)
 *      The benefit of using the const keyword is that the compiler might be able to make
 *      optimizations based on the knowledge that the value of the variable will not change.
 *      In addition, the compiler will try to ensure that the values won't be changed inadvertently.
 *
 *      (11)
 *      There is no set number or "guideline" limit to the number of parameters your functions can have.
 *      However, it is considered bad programming style for your functions to contain an inordinately high
 *      (eight or more) number of parameters. The number of parameters a function has also directly
 *      affects the speed at which it is called—the more parameters,
 *      the slower the function call. Therefore, if possible, you should minimize the
 *      number of parameters you use in a function. If you are using more than four parameters,
 *      you might want to rethink your function design and calling conventions.
 *
 *      (12)
 *      A static function is a function whose scope is limited to the current source file.
 *      Scope refers to the visibility of a function or variable.
 *      A static function is a function whose scope is limited to the current source file.
 *      Scope refers to the visibility of a function or variable.
 *      If the function or variable is visible outside of the current source file,
 *      it is said to have global, or external, scope.
 *      If the function or variable is not visible outside of the current source file,
 *      it is said to have local, or static, scope.
 *      Generally, if the function you are writing will not be used outside of the current source file,
 *      you should declare it as static.
 *
 *      (13)
 *      A function prototype tells the compiler what kind of arguments a function is looking to
 *      receive and what kind of return value a function is going to give back.
 *      This approach helps the compiler ensure that calls to a function are made correctly
 *      and that no erroneous type conversions are taking place.
 *
 *      (14)
 *      An array can be passed to a function by value by declaring in the called function the array
 *      name with square brackets ([ and ]) attached to the end. When calling the function,
 *      simply pass the address of the array (that is, the array's name) to the called function.
 *
 *      (15)
 *      A C function declared as PASCAL uses a different calling convention than a "regular" C function.
 *      Normally, C function parameters are passed right to left; with the PASCAL calling convention,
 *      the parameters are passed left to right.
 *
 *      (16) Is using exit() the same as using return?
 *      No. The exit() function is used to exit your program and return control to the operating system.
 *      The return statement is used to return from a function and return control to the calling function.
 *
 *      (17) Compilers for PC compatibles use two types of pointers. near pointers are 16 bits long
 *      and can address a 64KB range. far pointers are 32 bits long and can address a 1MB range.
 *      A far pointer can refer to information outside the 64KB data segment.
 *      Typically, such pointers are used with farmalloc() and such,
 *      to manage a heap separate from where all the rest of the data lives.
 *
 *      (18) A "stack trace" is a list of which functions have been called, based on this information.
 *      (19) NULL can be defined as ((void*)0), NUL as '\0'.
 *
 *      (20)
 *      Bus error: core dumped and Memory fault: core dumped are messages you might see from a program
 *      running under UNIX. They're more programmer friendly. Both mean that a pointer or an array
 *      subscript was wildly out of bounds. You can get these messages on a read or on a write.
 *      They aren't restricted to null pointer problems.
 *
 *      (21) ``null pointer''--which is distinguishable from all other pointer values and which is
 *      ``guaranteed to compare unequal to a pointer to any object or function.''
 *      That is, a null pointer points definitively nowhere; it is not the address of any
 *      object or function. The address-of operator & will never yield a null pointer,
 *      nor will a successful call to malloc.
 *
 *      (22) Can math operations be performed on a void pointer?
 *      No. Pointer addition and subtraction are based on advancing the pointer by a number of elements.
 *
 *      (23) How do you print an address?
 *      printf( "%P\n", (void*) buffer );
 *
 *      (24) A void pointer is a C convention for "a raw address."
 *      The compiler has no idea what type of object a void pointer "really points to."
 *      (25)  <stdarg.h>
 *      This defines some macros that let your program deal with variable numbers of arguments.
 *      (26)
 *      It is a useful, memory-saving technique for multiprogrammed timesharing systems.
 *      A Reentrant Procedure is one in which multiple users can share a single copy of a program
 *      during the same period. Reentrancy has 2 key aspects: The program code cannot modify itself,
 *      and the local data for each user process must be stored separately.
 *
 *      (27) thrashing:
 *      It is a phenomenon in virtual memory schemes when the processor spends most of its time swapping
 *      pages, rather than executing instructions. This is due to an inordinate number of page faults.
 *      (28)
 *      In a cached system, the base addresses of the last few referenced pages is maintained in registers
 *      called the TLB that aids in faster lookup. TLB contains those page-table entries that have been
 *      most recently used. Normally, each virtual memory reference causes 2 physical
 *      memory accesses- one to fetch appropriate page-table entry, and one to fetch the desired data.
 *      Using TLB in-between, this is reduced to just one physical memory access in cases of TLB-hit.
 *
 *      (29)
 *      A trap is a software interrupt, usually the result of an error condition.
 *
 *      (30)
 *      T *p = 0;
 *      delete p;
 *      No, the code has a problem. The program will crash in an attempt to delete a null pointer.
 *
 *      (31) What are the different types of STL containers?
 *      Following are the 3 types of STL containers:
 *      1. Adaptive containers - for e.g. queue, stack
 *      2. Associative containers - for e.g. set, map
 *      3. Sequence containers - for e.g. vector, deque
 *
 *      (32) What is reference variable in C++?
 *      A reference variable is just like pointer with few differences.
 *      It is declared using & operator. A reference variable must always be initialized.
 *      The reference variable once defined to refer to a variable can’t be changed to point
 *      to other variable. You can't create an array of references the way it is possible with pointer.
 *
 *      (33) What is abstraction?
 *      The process of hiding unnecessary data and exposing essential features is called abstraction.
 *      Abstraction is separating the logical properties from implementation details.
 *
 *      (34) What is abstract class?
 *      Abstract classes are mainly used in inheritance and cannot be instantiated.
 *      They are used as base classes and contain at least one pure virtual function.
 *      Example:
 *      class AB
 *      {
        public:
        virtual void f() = 0;
        };

        (35) Pointer vs. reference.
        When a reference is created, it can’t reference another object.
        This can be done with pointers. References cannot be null whereas pointers can be.
        References cannot be uninitialized and it is not possible to refer directly
        to a reference object after it is defined.
        (36)
        The this keyword is used to represent an object that invokes the member function.
        It points to the object for which this function was called. It is automatically passed to a
        member function when it is called.
        e.g. when you call A.func(), this will be set to the address of A.

        (37) What is the difference between inline functions and macros?
        A macro is a fragment of code which has been given a name. Whenever the name is used,
        it is replaced by the contents of the macro. There are two kinds of macros: Object-like macros
        and function-like macros. Inline function is a function that is expanded in line when the
        function is called. That is the compiler replaces the function call with the function code
        (similar to macros).
        The disadvantage of using macros is that the usual error checking does not occur during compilation.

        (38)
        Vector is one type of standard container provided by C++ library. The vector class supports
        dynamic array ie it can grow as needed. It supports all the functions of an
        array (ie accessing array elements using subscript notation) at the same time provides
        the flexibility of changing size of array at runtime to accommodate changing program conditions.
        Deque is a double ended queue. That is, it’s a sequence optimized so that operations at
        both ends are efficient.
        Maps on the other hand contain unique key/value pairs and sorted by keys.

        (39)
        Storage class defined for a variable determines the accessibility and longevity of the variable.
        The accessibility of the variable relates to the portion of the program that has access
        to the variable. The longevity of the variable refers to the length of time the variable
        exists within the program.
        Auto:
        Automatic variable, also called as local variable and it has scope only within the function
        block where it is defined.
        External:
        External variable are defined outside any function and memory is set aside for this
        type of variable once it is declared and remained until the end of the program.
        These variables are also called global variables.
        Static:
        The static automatic variables, as with local variables, are accessible only within the
        function in which it is defined. Static automatic variables exist until the program ends
        in the same manner as external variables. In order to maintain value between function calls,
        the static variable takes its presence.
 *
 *
 */
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include "circular.h"
#include "mmap_t.h"
#include "bserach.h"
#include "array.h"
#include "bit.h"
#include "strings.h"

/* Bit Masking */
/* Bit masking can be used to switch a character
   between lower case and upper case */
#define BIT_POS(N)            ( 1U << (N) )
#define SET_FLAG(N, F)        ( (N) |= (F) )
#define CLR_FLAG(N, F)        ( (N) &= -(F) )
#define TST_FLAG(N, F)        ( (N) & (F) )
#define BIT_RANGE(N, M)       ( (BIT_POS((M)+1 - (N))-1) << (N) )
#define BIT_RANGE_2(N, M)     (~((0-1)<< M)) << N //from position N set M bits
#define BIT_SHIFTL(B, N)      ( (unsigned)(B) << (N) )
#define BIT_SHIFTR(B, N)      ( (unsigned)(B) >> (N) )
#define SET_MFLAG(N, F, V)    ( CLR_FLAG(N, F), SET_FLAG(N, V) )
#define CLR_MFLAG(N, F)       ( (N) &= ~(F) )
#define GET_MFLAG(N, F)       ( (N) & (F) )
#define SECOND_OCTAL_DIGIT BIT_RANGE(3, 5) /* 111000 */


typedef enum {
	FALSE = 0,
	TRUE
} BOOL;


int NUM_ELEMENTS = 3;
int ELEMENT_SIZE = 5;

jmp_buf saved_state;
void call_longjmp(void);

#ifdef __cplusplus                      /* Is __cplusplus defined? */
#define USING_C FALSE                   /* Yes, we are not using C */
#else
#define USING_C TRUE                    /* No, we are using C */
#endif

void byval_func(int[]);       /* the byval_func() function is passed an
                                 integer array by value */
void const_func(const int*); /* by reference */

int my_strlen(const char *str)
{
        int count = 0;
        while (*str++)
        {
            count++;
        }
        return count;
}

void call_longjmp(void)
{
     longjmp(saved_state, 1);
}

void print_version_info(void)
{
     printf("Date Compiled: %s\n", __DATE__);
     printf("Time Compiled: %s\n", __TIME__);
}
#if 0
time_t time_addition(volatile const struct timer_list *t, int a)
{
        int     n;
        int     x;
        time_t  then;
        x = 0;
        then = t->data;
        for (n = 0; n < 1000; n++)
        {
                x = x + a;
        }
       return (t->data - then);
}
#endif

void byval_func(int i[])
{
     int y;
     /* Print the contents of the integer array. */
     for (y=0; y<10; y++)
          printf("%d\n", i[y]);
}

/* The const_function receives an integer array by reference.
   Notice that the pointer is declared as const, which renders
   it unmodifiable by the const_func() function. */

void const_func(const int* i)
{
     int y;
     /* Print the contents of the integer array. */
     for (y=0; y<10; y++)
          printf("%d\n", *(i+y));
}

void qsort( void *base,
            size_t numElements,
            size_t sizeOfElement,
            int (*compFunct)( const void *, const void *) );

char table[ 3 ][ 5 ] = {"12345", "45678", "98765"};

//static char buf[] = "Now is the time for all good men ...";

int main(void) {
//	char* str="Hello Wolrd";
//	unsigned char ascii_char = 'A';        /*  char = 8 bits only */
//	int test_nbr = 10;
#ifdef __STDC__
     printf("Congratulations! You are conforming perfectly to the ANSI standards!\n");
#else
     printf("Shame on you, you nonconformist anti-ANSI rabble-rousing programmer!\n");
#endif

	print_version_info();
	if (USING_C == TRUE)
		printf("using c compiler now\n");

#ifdef long_jump_test
	int ret_code;
	printf("The current state of the program is being saved...\n");
	ret_code = setjmp(saved_state);
	if (ret_code == 1)
	{
	  printf("The longjmp function has been called.\n");
	  printf("The program's previous state has been restored.\n");
	  exit(0);
	}
	printf("I am about to call longjmp and\n");
	printf("return to the previous program state...\n");
	call_longjmp();
#endif

#ifdef bit_op
	  test_nbr = 300;
	  test_nbr *= 2;
	  test_nbr = 300;
	  test_nbr <<= 1;

	printf("Starting character = %c\n", ascii_char);
	/*  The 5th bit position determines if the character is
	uppercase or lowercase.
	5th bit = 0  - Uppercase
	5th bit = 1  - Lowercase      */
	printf("\nTurn 5th bit on = %c\n", SET_FLAG(ascii_char, BIT_POS(5)) );
	printf("Turn 5th bit off = %c\n\n", CLR_FLAG(ascii_char, BIT_POS(5)) );
	printf("Look at shifting bits\n");
	printf("=====================\n");
	printf("Current value = %d\n", test_nbr);
	printf("Shifting one position left = %d\n",
	test_nbr = BIT_SHIFTL(test_nbr, 1) );
	printf("Shifting two positions right = %d\n",
	BIT_SHIFTR(test_nbr, 2) );
	printf("a number with bit range 3 to 5 set = %d\n", SECOND_OCTAL_DIGIT);
	printf("a number set from bit position 3 with 3 bits long = %d\n",BIT_RANGE_2(3, 3));
	printf("a number set from bit position 3 with 4 bits long = %d\n",BIT_RANGE_2(3, 4));
#endif
#if 0
	char* env_string;
	env_string = getenv("PATH");
	if (env_string == (char*) NULL)
	  printf("\nYou have no PATH!\n");
	else
	  printf("\nYour PATH is: %s\n", env_string);

	int file_handle;
	/* Note that sopen() is not ANSI compliant */
	file_handle = sopen("C:\\DATA\\TEST.DAT", O_RDWR, SH_DENYNO);
	close(file_handle);


    float f1 = 3 / 4;
    float f2 = 3 / 4.0;
    printf("3 / 4 == %g or %g depending on the type used.\n", f1, f2);

	printf("my string length = %d\n", my_strlen(str));

	int x[10];
	int y;
	/* Set up the integer array. */
	for (y=0; y<10; y++)
	  x[y] = y;
	/* Call byval_func(), passing the x array by value. */
	//byval_func(x);
	const_func(x);

	qsort(table, 3,5, ( int (*)( const void *, const void * ) ) strcmp );
	printf("size of char = %ld, size of char* = %ld, size of void *=%ld.\n",
			sizeof(char), sizeof(char*), sizeof(void*));

	char* p;
	p = strtok(buf, " ");
	while (p) {
			printf("%s\n", p);
			p = strtok(NULL, " ");
	}
#endif

#ifdef cb
	circular_buffer cb_test;
	//cb_test.capacity = 10;
	//cb_test.sz = sizeof(int);
	cb_init(&cb_test, 10, sizeof(int));
	int item=5;
	cb_push_back(&cb_test, &item);
	item=6;
	cb_push_back(&cb_test, &item);
	cb_pop_front(&cb_test, &item);
	printf("cb popped = %d\n", item);
	cb_pop_front(&cb_test, &item);
	printf("cb popped = %d\n", item);
	cb_pop_front(&cb_test, &item);
#endif

	//mem_map();
	//umap_mem();
#if 0
	int size = 100;
	int num, i, key, position;
	   int low, high, list[size];

	   printf("\nEnter the total number of elements");
	   scanf("%d", &num);

	   printf("\nEnter the elements of list :");
	   for (i = 0; i < num; i++) {
	      scanf("%d", &list[i]);
	   }

	   low = 0;
	   high = num - 1;

	   printf("\nEnter element to be searched : ");
	   scanf("%d", &key);

	   position = binsearch(list, key, low, high);

	   if (position != -1) {
	      printf("\nNumber present at %d\n", (position + 1));
	   } else
	      printf("\n The number is not present in the list\n");
#endif
#ifdef array
	   //delete_dup();
	   //reverse_array_elements();
	   //int input_array[] = {1,3,5,7,9};
	   //array_insertion(&input_array[0], 5, 11, 6);
#endif
#if 0
	   unsigned int num  = 128;
	   count_ones(num);
	   int num1=25, num2=10;
	   printf("Numbers before Exchange num1=%d, num2=%d: \n", num1, num2);
	   swap_num(&num1, &num2);

	   printf("Numbers after Exchange : \n");
	   printf("Num1 = %d and Num2 = %d\n", num1, num2);

	   char a = 'a', *cptr;
	   cptr = &a;

	   printf("\nSize of Char Pointer : %d\n", sizeof(cptr));
#endif
	   // if you pass a string pointer with a string literal type to function ToUpper,
	   // char *str = "hello";
	   // It will cause segmentation fault because the *str can not be modified.
	   // it is in the initialized data section as a constant.
	   // Using char str[] worked because it is not in the static allocated data section.
	   // the other way to make it work is to pass the modified string through a second
	   // (char * result ) pointer.
#if 0
	   char str[] = "hello";
	   int i;
	   ToUpper(&str[0]);
	   printf ("after run upper: %s\n", str);
	   printf("%d\n",strtoint("0123"));
	   printf("\n%d\n",strtoint("0123ii"));
	   for (i =0; i< 6; i++)
		   printf ("fib number = %d, ", fib(i));
	   printf("\n");
#endif
#if 0
	   int x=5, y =10;
	   swap_t(&x, &y);
	   printf("after swap_t: x=%d, y=%d\n", x ,y);

	   char str1[]="hello";
	   char str2[]="world";
		stringSwap(&str1[0], &str2[0]);
	   printf("after stringSwap: str1=%s, str2=%s\n", &str1[0], &str2[0]);

	   //Foo(&x, &y);
	   //printf("after Foo: x=%d, y=%d\n", x ,y);
#endif
	   int test_array[] = {1,4,7,19,2,55};
	   int index = ReturnMaxFromArray(&test_array[0], 6);
	   if (index == -1)
		   printf("did not find the max\n");
	   else
		   printf("index =%p\n", &test_array[index]);
	   return 0;
}
