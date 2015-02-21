/*
 * strings.c
 *
 *  Created on: Jan 6, 2015
 *      Author: kqchen
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

//void putchar(int c)
//{
//	uart_tx(c);
//}

void ToUpper(char * S)
{
	char ch, *temp=S;
	printf("length of the string: %d\n", (int)strlen(S));
	while (*temp != '\0')
	{
		ch = *temp;
		//if ((ch >= 'a') && (ch <= 'z'))
		//	*temp= ch-'a'+'A';

		*temp=(ch >= 'a' && ch <= 'z')?(ch-'a'+'A'):ch;
		temp++;
	}
}

int strtoint(char *s)
{
	int index = 0, flag = 0;

	while( *(s+index) != '\0')
	{
		if( (*(s + index) >= '0') && *(s + index) <= '9')
		{
			flag = 1;
			index++;
		}
	else
		{
			flag = 0;
			break;
		}
	}

	if( flag == 1 )
		return atoi(s);
	else
		return 0;
}

//print integer using only putchar
//
//	recursive version
//
#if 0
void print_num_recursive ( int Num )
{
	char ch = '0';
	if ( Num == 0 )
		return;
	print_num_recursive( Num / 10 );
	puthcar( ch + Num % 10 );
}
#endif


int fib( N ) //iterative version
{
	int f, f1 =1, f2 = 1, i;

	if ( N < 2 )
		return 1;
	for ( i = 1; i < N; i++)
	{
		f = f1 + f2;
		f1= f2;
		f2 = f;
	}

	return f;
}

