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

#define ARR_LENGTH 5


using namespace std;

int main()
{
    srand(time(nullptr));

    /*Distinct 100 numbers from 0-99 Generator*/
//    std::vector<int> numbers;
//
//    numbers.reserve(100);
//    for(int i=0; i<100; i++)       // add 0-99 to the vector
//            numbers.push_back(i);
//
//    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

    DirectedGraph graph(10);
    graph.addVertex(2);
    graph.addVertex(4);
    graph.addVertex(6);

    graph.addEdge(2, 4, 10);

    clock_t start = clock();

    cout<<"Original Array:"<<endl;
//    Print::printArray(array, 6);
    Print::printGraph(graph);



    double timeElapsed = double(clock()-start)/CLOCKS_PER_SEC * 1000;
    cout<<"Time Elapsed: "<<fixed<<timeElapsed<<" ms"<<endl;
}

