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

    UndirectedGraph graph(10);
    for(int i=0;i<=8;i++)
        graph.addVertex(i);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(1, 2, 8);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(5, 4, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 8, 6);
    graph.addEdge(6, 7, 1);
    graph.addEdge(7, 8, 7);


    clock_t start = clock();

    cout<<"Original Array:"<<endl;
//    Print::printArray(array, 6);
//    Print::printGraph(graph);
//    DijkstraPath a = ShortestPath::dijkstra(graph, 0);
//    Print::printVector(a.prevVertex);
//    Print::printVector(a.distance);
    ShortestPath::shortestPaths(graph, 0);


//    vector<int> adjacent = graph.getAdjacentVertices(10);
//    Print::printVector(adjacent);

    double timeElapsed = double(clock()-start)/CLOCKS_PER_SEC * 1000;
    cout<<"Time Elapsed: "<<fixed<<timeElapsed<<" ms"<<endl;
}

