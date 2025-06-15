//
// Created by Isai Gordeev on 25/05/2025.
//

#include "hash.h"
#include "stdlib.h"
#include "stdio.h"

#define HASH_SIZE 1000

int hash(int key) {
  return key & HASH_SIZE;
}

LRUHashTable *createLRUHashTable() {
  LRUHashTable *hash_table = malloc(sizeof(*hash_table));

  if (!hash_table) {
    perror("Failed to allocate memory");
    return NULL;
  }

  return hash_table;
}

LRUHashTable *initLRUHashTable(int capacity) {
  LRUHashTable *hash_table = createLRUHashTable();

}
