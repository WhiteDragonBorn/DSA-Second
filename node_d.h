#pragma once

#include "apartment.h"

typedef my_apartment::apartment dtype;

class Node_d {
 public:
  dtype data;
  Node_d* next;
  Node_d* prev;

  Node_d(const dtype& elem) : data(elem) {
    next = nullptr;
    prev = nullptr;
  }
};
