//
// Created by Isai Gordeev on 25/05/2025.
//

#ifndef LRU_HASH_H
#define LRU_HASH_H

#include "node.h"
typedef struct LRUHashTable {
  int capacity;
  Node **hashtable;
} LRUHashTable;

int hash(int key);

LRUHashTable *createLRUHashTable();
LRUHashTable *initLRUHashTable(int capacity);
void freeLRUHashTable(LRUHashTable *hash_table);

#endif //LRU_HASH_H
