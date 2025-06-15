//
// Created by Isai Gordeev on 25/05/2025.
//

#ifndef LRU_HASH_H
#define LRU_HASH_H
#define HASH_SIZE 1000
#define QUEUE_CAPACITY 1000

#include "node.h"

typedef struct LRUHashTable {
  int capacity;
  Node **hashtable;
} LRUHashTable;

int hash(int key);

LRUHashTable *createLRUHashTable();
LRUHashTable *initLRUHashTable(int capacity);
void freeLRUHashTable(LRUHashTable *hash_table);

int hash_table_put(LRUHashTable *hash_table, int value, Node *node);
int hash_table_contains(LRUHashTable *hash_table, int value, int *found);
Node *hash_table_get_last_bucket_node(const LRUHashTable *hash_table, int idx);
int hash_table_remove(LRUHashTable *hash_table, int value);

#endif //LRU_HASH_H
