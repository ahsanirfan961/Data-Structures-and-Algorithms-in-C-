//
// Created by ahsan on 12/3/23.
//
#include <iostream>
#include "Algorithm.h"
#include <cstdlib>
#include <ctime>
#define ARR_LENGTH 100

using namespace std;

int main()
{
    srand(time(nullptr));
    int a[ARR_LENGTH];
    for(int& i : a)
        i = rand()%101;

//    SinglyLinkedListNode list;
//    for(int i=0;i<ARR_LENGTH;i++)
//        SinglyLinkedListNode::pushBack(&list, rand()%101);

    clock_t start = clock();

    cout<<"Original Array:"<<endl;
    Print::printArray(a, ARR_LENGTH);
//    Print::printLinkedList(list);

    cout<<"Sorted Array: "<<endl;
    Sort::countingSort(a, ARR_LENGTH);
    Print::printArray(a, ARR_LENGTH);
//    Sort::bubbleSort(list);
//    Print::printLinkedList(list);

    double timeElapsed = double(clock()-start)/CLOCKS_PER_SEC * 1000;
    cout<<"Time Elapsed: "<<fixed<<timeElapsed<<" ms"<<endl;
}

