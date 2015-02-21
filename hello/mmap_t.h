/*
 * mmap_t.h
 *
 *  Created on: Jan 1, 2015
 *      Author: kqchen
 */

#ifndef MMAP_T_H_
#define MMAP_T_H_

#define FILEPATH "/tmp/mmapped.bin"
#define NUMINTS (1000)
#define FILESIZE (NUMINTS * sizeof(int))

int mem_map();
int umap_mem();

#endif /* MMAP_T_H_ */
