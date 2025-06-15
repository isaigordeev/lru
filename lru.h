//
// Created by Isai Gordeev on 15/06/2025.
//

#ifndef LRU__LRU_H_
#define LRU__LRU_H_

#include "hash.h"
#include "chain.h"

typedef struct LRU {
  LRUCacheChain *chain;
  LRUHashTable *hash_table;
  int capacity;
} LRU;

// Initialize LRU cache with given capacity
LRU *lru_init(int capacity);

// Free the LRU cache and all associated resources
void lru_free(LRU *lru);

// Add a value to the LRU cache (or update if it exists)
// Returns 1 if added or updated successfully, 0 on failure
int lru_put(LRU *lru, int key, int value);

// Get a value by key from the LRU cache
// Returns 1 and sets *value if found, else returns 0
int lru_get(LRU *lru);
int lru_get_tail(LRU *lru);

// Check if a key exists in the LRU cache
int lru_contains(LRU *lru, int key);

// Remove a key from the LRU cache
// Returns 1 if removed, 0 if not found
int lru_remove(LRU *lru, int key);

// Get current size of the cache
int lru_size(const LRU *lru);

// Return pointer to the head (most recently used) node
Node *lru_get_head(const LRU *lru);

// Return pointer to the tail (least recently used) node
Node *lru_get_tail(const LRU *lru);

#endif //LRU__LRU_H_
