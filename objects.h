//
// Created by Isai Gordeev on 25/05/2025.
//

#ifndef LRU_OBJECTS_H
#define LRU_OBJECTS_H

#include "chain.h"
typedef struct Node {
  int key;
  int value;
  struct Node *prev;
  struct Node *next;
} Node;

typedef struct LRUHashTable {
  int capacity;
  Node **hashtable;
} LRUHashTable;

LRUHashTable *createLRUHashTable();

#endif //LRU_OBJECTS_H
