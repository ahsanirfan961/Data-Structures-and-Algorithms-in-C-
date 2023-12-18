//
// Created by ahsan on 12/3/23.
//
#include <iostream>
#include "Algorithm.h"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
#include <algorithm>

#define ARR_LENGTH 3

using namespace std;

int main()
{
    srand(time(nullptr));

    /*Distinct 100 numbers from 0-99 Generator*/
    std::vector<int> numbers;

    numbers.reserve(100);
    for(int i=0; i<100; i++)       // add 0-99 to the vector
            numbers.push_back(i);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

//    Print::printVector(numbers);

    /*Array*/
//    int a[ARR_LENGTH];
//    for(int& i : a)
//        i = rand()%101;

//    int temp[8][8] = {{ 1, 1, 1, 1, 1, 1, 1, 1 },
//                      { 1, 1, 1, 1, 1, 1, 0, 0 },
//                      { 1, 0, 0, 1, 1, 0, 1, 1 },
//                      { 1, 2, 2, 2, 2, 0, 1, 0 },
//                      { 1, 1, 1, 2, 2, 0, 1, 0 },
//                      { 1, 1, 1, 2, 2, 2, 2, 0 },
//                      { 1, 1, 1, 1, 1, 2, 1, 1 },
//                      { 1, 1, 1, 1, 1, 2, 2, 1 } };
//
//    int** screen = new int*[8];
//    for (int i = 0; i < 8; i++) {
//        screen[i] = new int[8];
//        for (int j = 0; j < 8; j++) {
//            screen[i][j] = temp[i][j];
//        }
//    }

    /*Linked List*/
//    SinglyLinkedList list;
//    for(int i=0;i<ARR_LENGTH;i++)
//        list.pushBack(rand()%101);

    /*BST*/
    BST tree;
    for(int i=0;i<ARR_LENGTH;i++)
        tree.add(numbers[i]);


    clock_t start = clock();

    cout<<"Original Array:"<<endl;
//    Print::printArray(a, ARR_LENGTH);
//    Print::printLinkedList(list);
//    Print::printArray(screen, 8, 8);
    tree.print();


//    cout<<"Sorted Array: "<<endl;
//    Sort::bitonicSort(a, ARR_LENGTH);
//    Print::printArray(a, ARR_LENGTH);
//    cout<<"Count: "<<list.length()<<endl;
//    Print::printLinkedList(list);
//    ScreenColoring::floodFill(screen, 8, 8, 4, 4, 3);
//    Print::printArray(screen, 8, 8);

    double timeElapsed = double(clock()-start)/CLOCKS_PER_SEC * 1000;
    cout<<"Time Elapsed: "<<fixed<<timeElapsed<<" ms"<<endl;
}

