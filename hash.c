//
// Created by Isai Gordeev on 25/05/2025.
//

#include "hash.h"
#include "stdlib.h"
#include "stdio.h"
#include "errors.h"
#include <stdbool.h>
#include "chain.h"

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

int hash_table_put(LRUHashTable *hash_table, int value) {
  if (!hash_table) {
    return LRU_ERR_NULL;
  }

  if (!hash_table->hashtable) {
    return LRU_ERR_NULL;
  }

  int hash_index = hash(value);

  Node *last_node = hash_table_get_last_bucket_node(hash_table, hash_index);

  if (!last_node) {
    last_node = createNode(hash_index, value, NULL, NULL, NULL);
  }
  last_node->bucket_next = createNode(hash_index, value, NULL, NULL, NULL);

  return LRU_SUCCESS;
}

Node *hash_table_get_last_bucket_node(LRUHashTable *hash_table, int idx) {
  if (!hash_table->hashtable[idx]) {
    return NULL;
  } else {
    Node *curr = hash_table->hashtable[idx];
    while (curr) {
      curr = curr->bucket_next;
    }
    return curr;
  }
}

int hash_table_contains(LRUHashTable *hash_table, int value) {
  if (!hash_table) {
    return LRU_ERR_NULL;
  }

  int idx = hash(value);

  if (!hash_table->hashtable[idx]) {
    return false;
  } else {
    Node *current = hash_table->hashtable[idx];

    while (current) {
      if (current->value == value) {
        return true;
      }
      current = current->bucket_next;
    }
  }

  return false;
}




