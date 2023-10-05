#include "linkedList.h"

using std::cout;
using std::endl;

void my_linkedList::linkedList::printList() {
  Node_d* temp = head;
  if (!isEmpty()) {
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  } else {
    cout << "Empty list";
  }
}

void my_linkedList::linkedList::addBeforeNode(Node_d*& curNode,
                                              const dtype& elem) {
  Node_d* newNode = new Node_d(elem);

  newNode->next = curNode;
  newNode->prev = curNode->prev;
  curNode->prev = newNode;

  if (curNode == head) {
    head = newNode;
  } else {
    newNode->prev->next = newNode;
  }
}

void my_linkedList::linkedList::addToHead(const dtype& elem) {
  if (isEmpty()) {
    head = new Node_d(elem);
    tail = head;
  } else {
    addBeforeNode(head, elem);
  }
}

void my_linkedList::linkedList::addAfterNode(Node_d*& curNode,
                                             const dtype& elem) {
  Node_d* newNode = new Node_d(elem);

  newNode->next = curNode->next;
  curNode->next = newNode;
  newNode->prev = curNode;

  if (curNode == tail) {
    tail = newNode;
  } else {
    newNode->next->prev = newNode;
  }
}

//
// typedef Node_d* DList;
//
// void init(DList& head, DList& tail) {
//  head = nullptr;
//  tail = nullptr;
//}
//
// DList init(DList& head) {
//  head = nullptr;
//  return head;
//}
//
//
//

//

//

//
// void deleteAfterNode(const DList& curNode, DList& tail) {
//  DList delNode = curNode->next;
//  if (delNode != nullptr) {
//    curNode->next = delNode->next;
//    if (delNode == tail) {
//      tail = curNode;
//    }
//    else {
//      delNode->next->prev = curNode;
//    }
//
//    delNode->next = nullptr;
//    delNode->prev = nullptr;
//    delete delNode;
//    delNode = nullptr;
//  }
//}
//
// void deleteBeforeNode(const DList& curNode, DList& head) {
//  DList delNode = curNode->prev;
//  if (delNode != nullptr) {
//    curNode->prev = delNode->prev;
//    if (delNode == head) {
//      head = curNode;
//    }
//    else {
//      delNode->prev->next = curNode;
//    }
//
//    delNode->next = nullptr;
//    delNode->prev = nullptr;
//    delete delNode;
//    delNode = nullptr;
//  }
//}
//
// void deleteCurrentNode(DList* head_ref, DList delNode) {
//  if (*head_ref == nullptr || delNode == nullptr) return;
//
//  if (*head_ref == delNode) *head_ref = delNode->next;
//
//  if (delNode->next != nullptr) delNode->next->prev = delNode->prev;
//
//  if (delNode->prev != nullptr) delNode->prev->next = delNode->next;
//
//  delete delNode;
//}
//
// void Clear(DList& head, DList& tail) {
//  while (!isEmpty(head)) {
//    deleteCurrentNode(&head, head);
//  }
//}
//
