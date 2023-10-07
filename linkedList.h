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
  linkedList(const linkedList& other);
  ~linkedList() { clear(); }

  Node_d* getHead() const { return head; }
  Node_d* getTail() const { return tail; }
  void setHead(Node_d*& newHead) { head = newHead; }
  void setTail(Node_d*& newTail) { tail = newTail; }

  void addBeforeNode(Node_d* curNode, const dtype& elem);
  void addToHead(const dtype& elem);
  void addAfterNode(Node_d* curNode, const dtype& elem);

  void deleteCurrentNode(Node_d* delNode);
  void deleteAfterNode(Node_d* curNode);
  void deleteBeforeNode(Node_d* curNode);

  void printList();
  void clear();

  Node_d* searchByStreetAndHouse(int street, int house, Node_d* begin, Node_d* end);

  void deleteApartmentsByStreetAndHouse(int street, int house);


  linkedList& operator=(const linkedList& other);
};
}  // namespace my_linkedList
