//
// Created by Isai Gordeev on 22/05/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "chain.h"

int main() {
  LRUHashTable *hash_table = initLRUHashTable(HASH_SIZE);
  if (!hash_table) {
    fprintf(stderr, "Failed to initialize LRUHashTable\n");
    return EXIT_FAILURE;
  }

  LRUCacheChain *chain = initLRUCacheChain(HASH_SIZE, NULL, NULL);
  if (!chain) {
    fprintf(stderr, "Failed to initialize LRUCacheChain\n");
    freeLRUHashTable(hash_table);
    return EXIT_FAILURE;
  }


  // Cleanup
  freeLRUCacheChain(chain);
  freeLRUHashTable(hash_table);

  return EXIT_SUCCESS;
}