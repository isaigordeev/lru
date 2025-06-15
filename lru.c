//
// Created by Isai Gordeev on 15/06/2025.
//

#include "lru.h"

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