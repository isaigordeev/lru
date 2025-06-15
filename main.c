//
// Created by Isai Gordeev on 22/05/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "chain.h"
#include "lru.h"

int main() {

  LRU *lru = lru_init(HASH_SIZE, QUEUE_CAPACITY);

  lru_put(lru, 6);
  lru_put(lru, 8);

  // Cleanup
  lru_free(lru);

  return EXIT_SUCCESS;
}