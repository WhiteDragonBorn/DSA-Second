#include "linkedList.h"

using std::cout;
using std::endl;

my_linkedList::linkedList::linkedList(const linkedList& other) {
  Node_d* p = other.head;
  if (p != nullptr) {
    head = new Node_d(p->data);
    tail = head;
    p = p->next;
    Node_d* h = head;
    while (p != nullptr) {
      this->addAfterNode(h, p->data);
      p = p->next;
      h = h->next;
    }
  } else {
    head = nullptr;
    tail = nullptr;
  }
  cout << "constr";
}

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

void my_linkedList::linkedList::addBeforeNode(Node_d* curNode,
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

void my_linkedList::linkedList::addAfterNode(Node_d* curNode,
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

void my_linkedList::linkedList::deleteCurrentNode(Node_d* delNode) {
  Node_d** head_ref = &head;
  if (*head_ref == nullptr || delNode == nullptr) return;

  if (*head_ref == delNode) *head_ref = delNode->next;

  if (delNode->next != nullptr) delNode->next->prev = delNode->prev;

  if (delNode->prev != nullptr) delNode->prev->next = delNode->next;

  delete delNode;
}

void my_linkedList::linkedList::deleteAfterNode(Node_d* curNode) {
  Node_d* delNode = curNode->next;
  if (delNode != nullptr) {
    curNode->next = delNode->next;
    if (delNode == tail) {
      tail = curNode;
    } else {
      delNode->next->prev = curNode;
    }

    delNode->next = nullptr;
    delNode->prev = nullptr;
    delete delNode;
    delNode = nullptr;
  }
}

void my_linkedList::linkedList::deleteBeforeNode(Node_d* curNode) {
  Node_d* delNode = curNode->prev;
  if (delNode != nullptr) {
    curNode->prev = delNode->prev;
    if (delNode == head) {
      head = curNode;
    } else {
      delNode->prev->next = curNode;
    }

    delNode->next = nullptr;
    delNode->prev = nullptr;
    delete delNode;
    delNode = nullptr;
  }
}

void my_linkedList::linkedList::clear() {
  while (!isEmpty()) {
    deleteCurrentNode(head);
  }
}

my_linkedList::linkedList& my_linkedList::linkedList::operator=(
    const linkedList& other) {
  clear();

  Node_d* p = other.head;
  if (p != nullptr) {
    head = new Node_d(p->data);
    tail = head;
    p = p->next;
    Node_d* h = head;
    while (p != nullptr) {
      this->addAfterNode(h, p->data);
      p = p->next;
      h = h->next;
    }
  }
  cout << "copy";
  return *this;
}

Node_d* my_linkedList::linkedList::searchByStreetAndHouse(int street, int house,
                                                          Node_d* begin,
                                                          Node_d* end) {
  Node_d* result = nullptr;
  if (begin == nullptr || end == nullptr) return result;

  Node_d* temp = begin;
  while (!result && temp != end->next) {
    if (temp->data.getStreet() == street && temp->data.getHouse() == house) {
      result = temp;
    } else {
      temp = temp->next;
    }
  }

  return result;
}

void my_linkedList::linkedList::deleteApartmentsByStreetAndHouse(int street,
                                                                 int house) {
  Node_d* start = nullptr;
  start = searchByStreetAndHouse(street, house, head, tail);
  if (start) {
    while (start != nullptr && start->data.getHouse() == house &&
           start->data.getStreet() == street) {
      Node_d* temp = start->next;
      deleteCurrentNode(start);
      start = temp;
    }
  } else {
    cout << "No such apartments." << endl;
  }
}
