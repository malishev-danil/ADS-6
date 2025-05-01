// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <stdexcept>
template<typename T>
class TPQueue {

 private:
struct Node {
T data;
Node* next;
Node(const T& data_) : data(data_), next(nullptr) {}
};
Node* head;

 public:
TPQueue() : head(nullptr) {}
~TPQueue() {
while (head) {
Node* temp = head;
head = head->next;
delete temp;
}
}
void push(const T& item) {
Node* newNode = new Node(item);
if (!head || item.prior > head->data.prior) {
newNode->next = head;
head = newNode;
} else {
Node* current = head;
while (current->next && current->next->data.prior >= item.prior) {
current = current->next;
}
newNode->next = current->next;
current->next = newNode;
}
}
T pop() {
if (!head) {
throw std::out_of_range("Очередь пуста");
}
Node* temp = head;
T result = temp->data;
head = head->next;
delete temp;
return result;
}
bool empty() const {
return head == nullptr;
}
void print() const {
Node* current = head;
std::cout << "Очередь: ";
while (current) {
std::cout << std::string("(") + current->data.ch + ", pri=" +
  std::to_string(current->data.prior) + ") -> ";
current = current->next;
}
std::cout << "NULL\n";
}
};
struct SYM {
char ch;
int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
