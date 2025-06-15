//
// Created by Isai Gordeev on 25/05/2025.
//

#ifndef LRU_NODE_H
#define LRU_NODE_H

#include "stdlib.h"

typedef struct Node {
  int key;
  int value;
  struct Node *prev;
  struct Node *next;
} Node;

Node *createNode(int key, int value, struct Node *prev, struct Node *next);

#endif //LRU_NODE_H
