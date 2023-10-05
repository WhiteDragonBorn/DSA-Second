#pragma once

#include <iostream>

#include "apartment.h"

typedef my_apartment::apartment dtype;

namespace my_linkedList {

class linkedList {
 private:
  struct Node_d {
    dtype data;
    Node_d* next;
    Node_d* prev;

    Node_d(const dtype& elem) : data(elem) {
      next = nullptr;
      prev = nullptr;
    }
  };

  Node_d *head, *tail;

  bool isEmpty() { return head == nullptr; }

 public:
  linkedList() : head(nullptr), tail(nullptr) {}
  Node_d*& getHead() { return head; }
  Node_d*& getTail() { return tail; }
  void addBeforeNode(Node_d*& curNode, const dtype& elem);
  void addToHead(const dtype& elem);
  void addAfterNode(Node_d*& curNode, const dtype& elem);
  void printList();
};
}  // namespace my_linkedList
