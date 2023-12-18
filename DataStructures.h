//
// Created by ahsan on 12/3/23.
//

#ifndef DATA_STRUCTURES___ALGORITHMS_DATASTRUCTURES_H
#define DATA_STRUCTURES___ALGORITHMS_DATASTRUCTURES_H
#include <iostream>
#include "Algorithm.h"

class Array
{
public:
    static void flipArray(int array[], int length, int i=-1);
    static int maxElement(const int array[], int length);
    static int minElement(const int array[], int length);
    static int maxIndex(const int array[], int length);
    static int minIndex(int array[], int length);
    static void sortedMerge(int array1[], int start, int middle, int end);
    static void copyArray(int *copiedTo, const int *copiedFrom, int fromIndex, int end);
};

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode():data(0), next(nullptr){}
    explicit SinglyLinkedListNode(int data):data(data), next(nullptr){}
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode* head;

    SinglyLinkedList():head(nullptr){}
    void pushBack(int data);
    int length() const;
};

class Queue
{
    int* array{};
    int front;
    int rear;
    int capacity;
public:
    Queue():front(0), rear(0), capacity(0){}
    explicit Queue(int size);
    ~Queue(){delete[] array;}
    void operator=(const Queue&);
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(int data);
    int dequeue();
    int getSize();
};

struct Vector2i
{
    int x;
    int y;
    Vector2i(int x, int y):x(x), y(y){}
};

class Stack
{
    friend class Print;
    int *array;
    int top;
    int size;
    int elements;
public:
    explicit Stack(int size);
    void push(int data);
    bool isFull() const;
    bool isEmpty() const;
    int pop();
    int topElement();
};

class Utility
{
public:
    static void swap(int& a, int& b);
};

#endif //DATA_STRUCTURES___ALGORITHMS_DATASTRUCTURES_H
