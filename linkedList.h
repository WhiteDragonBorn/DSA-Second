#pragma once

#include <iostream>
typedef int dtype;

class linkedList {
  struct Node_d {
    dtype data;
    Node_d* next;
    Node_d* prev;

    Node_d(const dtype& elem) {
      data = elem;
      next = nullptr;
      prev = nullptr;
    }
  };

  Node_d *head, *tail;

 public:
  linkedList() : head(nullptr), tail(nullptr) {}

};
