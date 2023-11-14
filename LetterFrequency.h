#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

class LetterNode {
public:
    LetterNode(char chr);
    ~LetterNode();
    void increaseFrequency();
    char getLetter();
    int getFrequency();
    LetterNode* getNext();
    void setNext(LetterNode* next);
    void setPrev(LetterNode* prev);
    LetterNode* getPrev();

private:
    int frequency;
    char letter;
    LetterNode* next;
    LetterNode* prev;
};

class LetterFrequencyList {

public:
    LetterFrequencyList();
    ~LetterFrequencyList();

    bool append(char letter);
    bool insertInOrder(char letter);
    int getFrequency(char letter);
    bool remove(char letter);
    void print();
    LetterNode* find(char letter);

private:
    LetterNode* head;
    LetterNode* tail;
};
