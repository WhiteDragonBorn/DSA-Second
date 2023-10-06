#pragma once

#include <iostream>

#include "apartment.h"
#include "node_d.h"

namespace my_linkedList {

class linkedList {
 private:
  Node_d *head, *tail;

  bool isEmpty() { return head == nullptr; }

 public:
  linkedList() : head(nullptr), tail(nullptr) {}
  const Node_d* getHead() const { return head; }
  const Node_d* getTail() const { return tail; }
  void setHead(Node_d*& newHead) { head = newHead; }
  void setTail(Node_d*& newTail) { tail = newTail; }
  void addBeforeNode(Node_d*& curNode, const dtype& elem);
  void addToHead(const dtype& elem);
  void addAfterNode(Node_d*& curNode, const dtype& elem);
  void printList();
};
}  // namespace my_linkedList
