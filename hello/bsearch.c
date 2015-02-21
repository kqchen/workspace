/*
 * bsearch.c
 *
 *  Created on: Jan 6, 2015
 *      Author: kqchen
 */
#include <stdio.h>
#include <stdlib.h>
#include "bserach.h"

// Binary Search function
int binsearch(int a[], int x, int low, int high) {
   int mid;

   if (low > high)
      return -1;

   mid = (low + high) / 2;

   if (x == a[mid]) {
      return (mid);
   } else if (x < a[mid]) {
      binsearch(a, x, low, mid - 1);
   } else {
      binsearch(a, x, mid + 1, high);
   }
   return 0;
}

Node * GetNthNode ( Node* Head , int NthNode )
{
	Node * pNthNode = NULL;
	Node * pTempNode = NULL;
	int nCurrentElement = 0;

	for ( pTempNode = Head; pTempNode != NULL; pTempNode = pTempNode->pNext )
	{
		nCurrentElement++;
		if ( nCurrentElement - NthNode == 0 )
		{
			pNthNode = Head;
		}
		else
		if ( nCurrentElement - NthNode > 0)
		{
			pNthNode = pNthNode->pNext;
		}
	}
	if (pNthNode )
	{
		return pNthNode;
	}
	else
		return NULL;
}



void delete_node(int key, Node **head)
{
  Node *current;
  Node *tmp;
  int find = 0;

  tmp = current = *head;

  while (current) {
    if(current->key != key) {
      tmp = current;
      current = current->pNext;
    }
    else {
/* head                                                      */
/* ---     ----      ---      ---      ---      ---          */
/*|   |==>|    | ==>|   | ==>|   | ==>|   | ==>|   |==>NULL  */
/* ---     ----      ---      ---      ---      ---          */
/* current                                                   */

    	if(current == *head) {
    		*head = current->pNext;
    	}
    	else if(current->pNext == NULL) {
	/*                                     tmp                   */
	/* ---     ----      ---      ---      ---      ---          */
	/*|   |==>|    | ==>|   | ==>|   | ==>|   | ==>|   |==>NULL  */
	/* ---     ----      ---      ---      ---      ---          */
	/*                                           current         */
    		tmp->pNext = NULL;
    	}
    	else {
	/*                   tmp                                     */
	/* ---     ----      ---      ---      ---      ---          */
	/*|   |==>|    | ==>|   | ==>|   | ==>|   | ==>|   |==>NULL  */
	/* ---     ----      ---      ---      ---      ---          */
	/*                           current                         */
    		tmp->pNext = current->pNext;
    	}
    	free(current);
    	return;
    }
  }
}

void insert_node(int key, Node **head)
{
	Node *cur;
	Node *new_node;
	Node *tmp;

	cur = tmp = *head;
	new_node = (Node *)malloc(sizeof(Node));

	if(cur == NULL) {
	  /* ---          */
	  /*|   |==> NULL */
	  /* ---          */
	  /* new          */
	  new_node->key = key;
	  *head = new_node;
	  return;
	}

	while (cur != NULL) {
	  if ( key >cur->key ) {
	    tmp = cur;
	    cur = cur->pNext;
	  }
	  else  {
	    /* ---     ----      ---      ---      ---      ---          */
	    /*|   |==>|    | ==>|   | ==>|   | ==>|   | ==>|   |==>NULL  */
	    /* ---     ----      ---      ---      ---      ---          */
	    /*         tmp       new      cur                          */
	    new_node->key = key;
	    new_node->pNext = cur;
	    tmp->pNext = new_node;
	    return;
	  }
	}

	if( cur == NULL) {
	    /* ---     ----      ---      ---      ---      ---          */
	    /*|   |==>|    | ==>|   | ==>|   | ==>|   | ==>|   |==>NULL  */
	    /* ---     ----      ---      ---      ---      ---          */
	    /*                                     tmp       new         */
	  new_node->key = key;
	  new_node->pNext = NULL;
	  tmp->pNext = new_node;
	}
}



