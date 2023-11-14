#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "LetterFrequency.h"

using namespace std;

LetterNode::LetterNode(char chr) {
    letter = chr;
    next = nullptr;
    prev = nullptr;
    frequency = 1;
}
LetterNode::~LetterNode() {
    cout << "Destroying " << letter << endl;
}
void LetterNode::increaseFrequency() {
    frequency++;
}
char LetterNode::getLetter() {
    return letter;
}
int LetterNode::getFrequency() {
    return frequency;
}
LetterNode* LetterNode::getNext() {
    return next;
}
void LetterNode::setNext(LetterNode* next) {
    this->next = next;
}
void LetterNode::setPrev(LetterNode* prev) {
    this->prev = prev;
}
LetterNode* LetterNode::getPrev() {
    return prev;
}


LetterFrequencyList::LetterFrequencyList() {
    head = nullptr;
    tail = nullptr;
}
LetterFrequencyList::~LetterFrequencyList() {
    LetterNode* prev;
    for (LetterNode* current = tail; current != nullptr; current = prev) {
        prev = current->getPrev();
        delete current;
    }
    cout << "Done destroying list\n";
}
bool LetterFrequencyList::append(char letter) {
    LetterNode* tmpPtr = new LetterNode(letter);
    if (head == nullptr) {
        head = tmpPtr;
        tail = tmpPtr;
    }
    else {
        for (LetterNode* current = head; current != nullptr; current = current->getNext()) {
            if (current->getLetter() == letter) {
                current->increaseFrequency();
                return false;
            }
        }
        LetterNode* tmpPtr = new LetterNode(letter);
        tail->setNext(tmpPtr);
        tmpPtr->setPrev(tail);
        tail = tmpPtr;

    }
    return true;
}

bool LetterFrequencyList::insertInOrder(char letter) {

    if (head == nullptr) {
        LetterNode* tmpPtr = new LetterNode(letter);
        head = tmpPtr;
        tail = tmpPtr;
        return true;
    }

    for (LetterNode* current = head; current != nullptr; current = current->getNext()) {
        if (current->getLetter() == letter) {
            current->increaseFrequency();
            return false;
        }
    }

    LetterNode* tmpPtr = new LetterNode(letter);

    if (letter < head->getLetter()) {
        tmpPtr->setNext(head);
        head->setPrev(tmpPtr);
        head = tmpPtr;
        return true;
    }

    LetterNode* current = head;

    while (current->getNext() != nullptr && letter > current->getNext()->getLetter()) {
        current = current->getNext();
    }

    tmpPtr->setNext(current->getNext());
    tmpPtr->setPrev(current);

    if (current->getNext() != nullptr) {
        current->getNext()->setPrev(tmpPtr);
    }
    else {
        tail = tmpPtr;
    }

    current->setNext(tmpPtr);

    return true;
}

int LetterFrequencyList::getFrequency(char letter) {
    int frequency = 0;
    if (head == nullptr) {
        return frequency;
    }
    else {
        for (LetterNode* current = head; current != nullptr; current = current->getNext()) {
            if (current->getLetter() == letter) {
                frequency = current->getFrequency();
            }
        }
    }
    return frequency;
}

bool LetterFrequencyList::remove(char letter) {
    if (head == nullptr) {
        return false;
    }
    for (LetterNode* current = head; current != nullptr; current = current->getNext()) {
        if (current->getLetter() == letter) {
            if (current != head && current != tail) {
                current->getPrev()->setNext(current->getNext());
                current->getNext()->setPrev(current->getPrev());
                delete current;
            }
            else if (current == head) {
                current->getNext()->setPrev(nullptr);
            }
            else if (current == tail) {
                current->getPrev()->setNext(nullptr);
            }
            return true;
        }
    }
    return false;
}

void LetterFrequencyList::print() {
    for (LetterNode* current = head; current != nullptr; current = current->getNext()) {
        cout << "| " << current->getLetter() << ":" << current->getFrequency() << " ";
        if (current->getNext() == nullptr) {
            cout << "| \n";
        }
    }
}

LetterNode* LetterFrequencyList::find(char letter) {
    if (head != nullptr) {
        for (LetterNode* current = head; current != nullptr; current = current->getNext()) {
            if (current->getLetter() == letter) {
                return current;
            }
        }
        return nullptr;
    }
    else {
        return nullptr;
    }
}