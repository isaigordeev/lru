//
// Created by Isai Gordeev on 25/05/2025.
//

#include "hash.h"

#define HASH_SIZE 1000

int hash(int key){
    return key & HASH_SIZE;
}

