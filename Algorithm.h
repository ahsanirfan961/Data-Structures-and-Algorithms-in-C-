//
// Created by ahsan on 12/3/23.
//

#ifndef CLION_ALGORITHM_H
#define CLION_ALGORITHM_H
#include <iostream>
#include "DataStructures.h"

using namespace std;

class SinglyLinkedListNode;

class Sort
{
    static int Partition(int array[], int start, int end);
public:
    static void bubbleSort(int array[], int length);
    static void bubbleSort(SinglyLinkedListNode& list);
    static void cycleSort(int array[], int length);
    static void pancakeSort(int array[], int length);
    static void insertionSort(int array[], int length);
    static void selectionSort(int array[], int length);
    static void bucketSort(int array[], int length);
    static void mergeSort(int array[], int length, int start=0, int end=-1);
    static void quickSort(int array[], int length, int start=0, int end=-9);
};


class Print
{
public:
    static void printArray(int array[], int length);
    static void printLinkedList(SinglyLinkedListNode& head);
};


#endif //CLION_ALGORITHM_H
