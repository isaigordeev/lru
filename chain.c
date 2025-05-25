//
// Created by Isai Gordeev on 25/05/2025.
//

#include "chain.h"
#include "stdlib.h"

typedef struct LRUCacheChain {
  int capacity;
  int size;
  struct Node *head;
  struct Node *tail;
} LRUCacheChain;

struct LRUCacheChain *createCacheChain(int capacity, Node *head, Node *tail) {
  struct LRUCacheChain *cache = malloc(sizeof(struct LRUCacheChain));

  if (cache == NULL) {
    return NULL;
  }

  cache->capacity = capacity;
  cache->head = head;
  cache->tail = tail;
  cache->size = 0;  // because empty

  return cache;
}

void freeLRUCacheChain(LRUCacheChain *chain) {
  if (chain == NULL) {
    return;
  }
  free(chain);
}