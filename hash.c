//
// Created by Isai Gordeev on 25/05/2025.
//

#include "hash.h"
#include "stdlib.h"
#include "stdio.h"
#include "errors.h"

int hash(int key) {
  return key % HASH_SIZE;
}

LRUHashTable *createLRUHashTable() {
  LRUHashTable *hash_table = malloc(sizeof(*hash_table));

  if (!hash_table) {
    perror("Failed to allocate memory for hash_table");
    return NULL;
  }

  return hash_table;
}

LRUHashTable *initLRUHashTable(int capacity) {

  if (capacity <= 0) {
    perror("Invalid capacity");
    return NULL;
  }

  LRUHashTable *hash_table = createLRUHashTable();

  hash_table->capacity = capacity;
  hash_table->hashtable = calloc(capacity, sizeof(Node *));

  if (!hash_table->hashtable) {
    perror("Failed to allocate memory for hash_table attribute ->hashtable");
    free(hash_table);
    return NULL;
  }

  return hash_table;
}

void freeLRUHashTable(LRUHashTable *hash_table) {

  if (!hash_table) {
    return;
  }

  if (hash_table->hashtable) {
    free(hash_table->hashtable);
  }

  free(hash_table);
}

int put(LRUHashTable *hash_table, int value) {
  if (!hash_table) {
    return LRU_ERR_NULL;
  }

  if (!hash_table->hashtable) {
    return LRU_ERR_NULL;
  }

  int hash_index = hash(value);

  Node *curr_node = createNode(hash_index, value, NULL, NULL);

  hash_table->hashtable[hash_index] = curr_node;

  return LRU_SUCCESS;
}




