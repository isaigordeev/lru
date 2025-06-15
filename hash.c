//
// Created by Isai Gordeev on 25/05/2025.
//

#include "hash.h"
#include "stdlib.h"
#include "stdio.h"
#include "errors.h"
#include <stdbool.h>
#include "node.h"

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

  // Free all nodes in the chain
  int i = 0;
  for (; i < hash_table->capacity; i = i + 1) {
    Node *current = hash_table->hashtable[i];
    while (current) {
      Node *next = current->bucket_next;
      freeNode(current);
      current = next;
    }
  }

  free(hash_table->hashtable);
  free(hash_table);
}

int hash_table_put(LRUHashTable *hash_table, int value, Node *node) {
  if (!hash_table || !hash_table->hashtable) {
    return LRU_ERR_NULL;
  }

  int hash_index = hash(value);

  node = createNode(hash_index, value, NULL, NULL, NULL);

  Node *last_node = hash_table_get_last_bucket_node(hash_table, hash_index);

  if (!last_node) {
    if (!node) {
      return LRU_ERR_ALLOC;
    }
    hash_table->hashtable[hash_index] = node;
  } else {
    if (!node) {
      return LRU_ERR_ALLOC;
    }
    last_node->bucket_next = node;
  }

  return LRU_SUCCESS;
}

Node *hash_table_get_last_bucket_node(const LRUHashTable *hash_table, const int idx) {
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

int hash_table_contains(LRUHashTable *hash_table, int value, int *found) {
  if (!hash_table || !found) {
    return LRU_ERR_NULL;
  }

  int idx = hash(value);
  Node *current = hash_table->hashtable[idx];

  while (current) {
    if (current->value == value) {
      *found = true;
      return LRU_SUCCESS;
    }
    current = current->bucket_next;
  }

  *found = false;
  return LRU_SUCCESS;
}

int hash_table_remove(LRUHashTable *hash_table, int value) {
  if (!hash_table) {
    return LRU_ERR_NULL;
  }

  int idx = hash(value);
  Node *current = hash_table->hashtable[idx];

  if (!current) {
    return LRU_SUCCESS;
  }

  Node *prev = NULL;

  while (current) {
    if (prev) {
      if (current->value == value) {
        prev->bucket_next = current->bucket_next;
        freeNode(current);
        return LRU_SUCCESS;
      }
    } else {
      hash_table->hashtable[idx] = current->next;
      freeNode(current);
      return LRU_SUCCESS;
    }
    prev = current;
    current = current->bucket_next;
  }

  return LRU_SUCCESS;
}




