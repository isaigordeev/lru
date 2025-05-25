//
// Created by Isai Gordeev on 25/05/2025.
//

#ifndef LRU_LRU_OBJECTS_H
#define LRU_LRU_OBJECTS_H

typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct LRUCacheChain {
    int capacity;
    int size;
    Node* head;
    Node* tail;
} LRUCacheChain;


LRUCacheChain* createCacheChain();

#endif //LRU_LRU_OBJECTS_H
