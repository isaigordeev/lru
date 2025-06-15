//
// Created by Isai Gordeev on 25/05/2025.
//

#include "chain.h"
#include "stdlib.h"

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
  chain->head = head;
  chain->tail = tail;
  chain->size = 0;  // empty on init

  return chain;
}

void freeLRUCacheChain(struct LRUCacheChain *chain) {
  if (!chain) return;

  // Free all nodes in the chain
  Node *current = chain->head;
  while (current) {
    Node *next = current->next;
    free(current);
    current = next;
  }

  // Finally free the chain struct itself
  free(chain);
}

int getCapacity(const LRUCacheChain *chain) {
  if (!chain) return -1;  // or some error value
  return chain->capacity;
}

int getSize(const LRUCacheChain *chain) {
  if (!chain) return -1;  // or some error value
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
  if (!node) return -1;  // or some sentinel/error value
  return node->key;
}

int getNodeValue(const Node *node) {
  if (!node) return -1;  // or some sentinel/error value
  return node->value;
}

