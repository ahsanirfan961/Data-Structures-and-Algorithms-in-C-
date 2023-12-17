//
// Created by ahsan on 12/3/23.
//

#ifndef CLION_ALGORITHM_H
#define CLION_ALGORITHM_H
#include <iostream>
#include "DataStructures.h"

using namespace std;

class SinglyLinkedListNode;
class SinglyLinkedList;
class Queue;

class Sort
{
    static int Partition(int array[], int start, int end);
public:
    __attribute__((unused)) static void bubbleSort(int array[], int length);
    static void bubbleSort(SinglyLinkedList& list);
    static void cycleSort(int array[], int length);
    static void countingSort(int array[], int length);
    static void pancakeSort(int array[], int length);
    static void gnomeSort(int array[], int length);
    static void pigeonHoleSort(int array[], int length);
    static void insertionSort(int array[], int length);
    static void selectionSort(int array[], int length);
    static void bucketSort(int array[], int length);
    static void mergeSort(int array[], int length, int start=0, int end=-1);
    static void quickSort(int array[], int length, int start=0, int end=-9);
};

class ScreenColoring
{
    /*Supporting Functions*/

    // supporting function for flood fill
    static bool isValid(int **screen, int width, int height, int pixelX, int pixelY, int prevColor, int newColor);
public:
    static void floodFill(int **screen, int width, int height, int pixelX, int pixelY, int newColor);
};

class Print
{
public:
    static void printArray(int array[], int length);
    static void printArray(int **array, int width, int height);
    static void printLinkedList(SinglyLinkedList& list);
    static void printQueue(Queue& queue);
};


#endif //CLION_ALGORITHM_H
