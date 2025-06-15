//
// Created by Isai Gordeev on 25/05/2025.
//

#ifndef LRU_HASH_H
#define LRU_HASH_H
#define HASH_SIZE 1000

#include "node.h"

typedef struct LRUHashTable {
  int capacity;
  Node **hashtable;
} LRUHashTable;

int hash(int key);

LRUHashTable *createLRUHashTable();
LRUHashTable *initLRUHashTable(int capacity);
void freeLRUHashTable(LRUHashTable *hash_table);

int put(LRUHashTable *hash_table, int value);
int contains(LRUHashTable *hash_table, int value);
int remove_value(LRUHashTable *hash_table, int value);

#endif //LRU_HASH_H
