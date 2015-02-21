/*
 * circular.c
 *
 *  Created on: Jan 1, 2015
 *      Author: kqchen
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "circular.h"

void cb_init(circular_buffer *cb, size_t capacity, size_t sz)
{
    cb->buffer = malloc(capacity * sz);
    if(cb->buffer == NULL) {
    	printf("%s, %d: cb init error", __FILE__, __LINE__);
    	return;
    }

    cb->buffer_end = (char *)cb->buffer + capacity * sz;
    cb->capacity = capacity;
    cb->count = 0;
    cb->sz = sz;
    cb->head = cb->buffer;
    cb->tail = cb->buffer;
}

void cb_free(circular_buffer *cb)
{
    free(cb->buffer);
    // clear out other fields too, just to be safe

}

void cb_push_back(circular_buffer *cb, const void *item)
{
    if(cb->count == cb->capacity) {
    	printf("%s, %d: cb push back error", __FILE__, __LINE__);
    	return;
    }

    memcpy(cb->head, item, cb->sz);
    cb->head = (char*)cb->head + cb->sz;
    if(cb->head == cb->buffer_end)
        cb->head = cb->buffer;
    cb->count++;
}

void cb_pop_front(circular_buffer *cb, void *item)
{
    if(cb->count == 0){
    	printf("%s, %d: cb_pop_front: empty cb.\n", __FILE__, __LINE__);
    	return;
    }
    memcpy(item, cb->tail, cb->sz);
    cb->tail = (char*)cb->tail + cb->sz;
    if(cb->tail == cb->buffer_end)
        cb->tail = cb->buffer;
    cb->count--;
}
#if 0
void cb_print(circular_buffer *cb)
{
	do {
	 if(cb->count == 0){
	    	printf("%s, %d: cb is empty now.\n", __FILE__, __LINE__);
	    	return;
	 }
	 printf ("cb->tail=0x%x, cb->head=0x%x, cb->count = %d\n", cb->tail, cb->head, cb->count);
	 cb->count--;
	} while (cb->count > 0);
}
#endif

