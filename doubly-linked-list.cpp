#include "doubly-linked-list.h"

DoublyLinkedList::Node::Node(DataType data) {
    value = data;
    prev = nullptr;
    next = nullptr;
}

DoublyLinkedList::DoublyLinkedList() {
    tail_ = head_= nullptr;
    size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    while (head_) {
        Node* temp = head_;
        head_ = temp->next;
        delete temp;
    }
}

unsigned int DoublyLinkedList::size() const {
    return size_;
}

unsigned int DoublyLinkedList::capacity() const {
    return  CAPACITY;
}

bool DoublyLinkedList::empty() const {
    return size_ == 0;

}

bool DoublyLinkedList::full() const {
    return (size_ == CAPACITY);
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    if (index >= size_)
        index = size_ - 1;

    Node* node = getNode(index);
    return node->value;
}

unsigned int DoublyLinkedList::search(DataType value) const {
    int index = 0;
    Node* temp = head_;
    while (temp) {
        if (temp->value == value)
            return index;
        temp = temp->next;
        index++;
    }
    return size();
}


void DoublyLinkedList::print() const {
    int index = 0;
    Node* temp = head_;
    while (temp-> next != nullptr) {
        std::cout << "| Node: "<< index << " Value: " << temp-> value << " | --> ";
        temp = temp-> next;
        index++;
    }
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {
    if (index >= size_ || full()) {
        return nullptr;
    }

    Node* finderNode = head_;
    for (int i = 0; i < index; i++) {
        finderNode = finderNode->next;
    }

    return finderNode;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index) {
    if (index > size() || full())
        return false;

    Node* newNode = new Node(value);

    if (index == 0) {
        newNode->next = head_;
        if (head_)
            head_->prev = newNode;
        head_ = newNode;
        if (size_ == 0)
            tail_ = newNode;
    } else if (index == size_) {
        newNode->prev = tail_;
        tail_->next = newNode;
        tail_ = newNode;
    }
    else {
        Node* prevNode = getNode(index - 1);
        Node* nextNode = prevNode->next;

        newNode->prev = prevNode;
        newNode->next = nextNode;

        prevNode->next = newNode;
        nextNode->prev = newNode;
    }

    size_++;
    return true;
}


bool DoublyLinkedList::insert_front(DataType value) {
    return insert(value, 0);
}


bool DoublyLinkedList::insert_back(DataType value) {
    return insert(value, size());
}


bool DoublyLinkedList::remove(unsigned int index) {
    if (index >= size_)
        return false;

    Node* removeNode = getNode(index);

    if (index == 0){
        head_ = removeNode->next;
        if (head_)
            head_->prev = nullptr;
        if (removeNode == tail_)
            tail_ = nullptr;
    }
    else if (removeNode == tail_){
        tail_ = tail_->prev;
        tail_->next = nullptr;
    }
    else {

        Node *prevNode = removeNode->prev;
        Node *nextNode = removeNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    delete removeNode;
    size_--;
    return true;
}


bool DoublyLinkedList::remove_front() {
    return remove(0);
}

bool DoublyLinkedList::remove_back() {
    return remove(size()-1);
}

bool DoublyLinkedList::replace(unsigned int index, DataType value) {
    if (index >= size())
        return false;

    Node *node = getNode(index);
    node->value = value;
    return true;
}
