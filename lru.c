//
// Created by Isai Gordeev on 15/06/2025.
//

#include "lru.h"
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

LRU *lru_create() {

  LRU *lru = malloc(sizeof(*lru));

  if (!lru) {
    perror("Failed to allocate memory for hash_table");
    return NULL;
  }
  return lru;
}

LRU *lru_init(int hash_size, int queue_capacity) {

  LRUHashTable *hash_table = initLRUHashTable(hash_size);
  if (!hash_table) {
    fprintf(stderr, "Failed to initialize LRUHashTable\n");
    return NULL;
  }

  LRUCacheChain *chain = initLRUCacheChain(queue_capacity, NULL, NULL);
  if (!chain) {
    fprintf(stderr, "Failed to initialize LRUCacheChain\n");
    freeLRUHashTable(hash_table);
    return NULL;
  }

  LRU *lru = lru_create();

  lru->hash_size = hash_size;
  lru->queue_capacity = queue_capacity;
  lru->chain = chain;
  lru->hash_table = hash_table;

  return lru;
}

void lru_free(LRU *lru) {

  if (!lru) {
    return;
  }

  if (!lru->chain) {
    freeLRUCacheChain(lru->chain);
    lru->chain = NULL;
  }

  if (lru->hash_table) {
    freeLRUHashTable(lru->hash_table);
    lru->hash_table = NULL;
  }

  // Finally free the LRU itself
  free(lru);
}