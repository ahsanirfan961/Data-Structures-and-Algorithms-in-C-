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

    static void pushBack(SinglyLinkedListNode* head, int data);
};

class Utility
{
public:
    static void swap(int& a, int& b);
};

#endif //DATA_STRUCTURES___ALGORITHMS_DATASTRUCTURES_H
