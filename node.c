//
// Created by Isai Gordeev on 25/05/2025.
//

#include "node.h"

Node *createNode(int key, int value, struct Node *prev, struct Node *next) {
  Node *node = malloc(sizeof(*node));
  if (!node) {
    return NULL;
  }

  node->key = key;
  node->value = value;
  node->prev = prev;
  node->next = next;

  return node;
}

void freeNode(Node *node) {
  if (!node) return;  // Handle NULL safely
  free(node);
}

