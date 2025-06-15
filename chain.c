//
// Created by Isai Gordeev on 25/05/2025.
//

#include "chain.h"
#include "stdlib.h"
#include "errors.h"
#include <stdbool.h>

// Allocates memory for LRUCacheChain struct only (no initialization)
struct LRUCacheChain *createLRUCacheChain() {
  struct LRUCacheChain *cache = malloc(sizeof(*cache));
  if (!cache) {
    return NULL;
  }
  return cache;
}

// Initializes a newly created LRUCacheChain with given capacity, head, tail
struct LRUCacheChain *initLRUCacheChain(int capacity, Node *head, Node *tail) {
  struct LRUCacheChain *chain = createLRUCacheChain();
  if (!chain) {
    return NULL;
  }

  chain->capacity = capacity;
  chain->size = 0;  // empty on init

  if (head == NULL && tail == NULL) {
    chain->head = NULL;
    chain->tail = NULL;
  } else {
    // Optional: if one is NULL but not the other, handle that case too
    chain->head = head;
    chain->tail = tail;
  }

  return chain;
}

int addNodeToHead(LRUCacheChain *chain, Node *node) {
  if (!chain || !node) {
    return LRU_ERR_NULL;
  }

  Node *head = getHead(chain);
  
  node->prev = NULL;
  node->next = head;

  if (!head) {
    chain->head = node;
    chain->tail = node;
  } else {
    head->prev = node;
    chain->head = node;
  }

  return LRU_SUCCESS;
}

void freeLRUCacheChain(struct LRUCacheChain *chain) {
  if (!chain) return;

  // Finally free the chain struct itself
  free(chain);
}

int getCapacity(const LRUCacheChain *chain) {
  if (!chain) return LRU_ERR_NULL;  // or some error value
  return chain->capacity;
}

int getSize(const LRUCacheChain *chain) {
  if (!chain) return LRU_ERR_NULL;  // or some error value
  return chain->size;
}

Node *getHead(const LRUCacheChain *chain) {
  if (!chain) return NULL;
  return chain->head;
}

Node *getTail(const LRUCacheChain *chain) {
  if (!chain) return NULL;
  return chain->tail;
}

// Get key and value from a node

int getNodeKey(const Node *node) {
  if (!node) return LRU_ERR_NULL;  // or some sentinel/error value
  return node->key;
}

int getNodeValue(const Node *node) {
  if (!node) return LRU_ERR_NULL;  // or some sentinel/error value
  return node->value;
}

