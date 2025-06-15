//
// Created by Isai Gordeev on 25/05/2025.
//

#include "hash.h"
#include "stdlib.h"

#define HASH_SIZE 1000

int hash(int key) {
  return key & HASH_SIZE;
}

LRUHashTable *createLRUHashTable() {
  LRUHashTable *hash_table = malloc(sizeof(struct LRUHashTable));
  if (hash_table != NULL) {
    return NULL;
  }

  return hash_table;
}
