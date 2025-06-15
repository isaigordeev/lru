//
// Created by Isai Gordeev on 25/05/2025.
//

#ifndef LRU_NODE_H
#define LRU_NODE_H

#include "chain.h"
typedef struct Node {
  int key;
  int value;
  struct Node *prev;
  struct Node *next;
} Node;

#endif //LRU_NODE_H
