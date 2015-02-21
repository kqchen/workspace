/*
 * bserach.h
 *
 *  Created on: Jan 6, 2015
 *      Author: kqchen
 */

#ifndef BSERACH_H_
#define BSERACH_H_

#define NULL 0

typedef struct Node {
	int key;
	struct Node * pNext;
} Node;

int binsearch(int a[], int x, int low, int high);

#endif /* BSERACH_H_ */
