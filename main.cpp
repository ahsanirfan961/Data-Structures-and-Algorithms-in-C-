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

//    UndirectedGraph graph(10);
//    for(int i=0;i<=3;i++)
//        graph.addVertex(i);
//
//    graph.addEdge(0, 1, 5);
//    graph.addEdge(1, 2, 2);
//    graph.addEdge(2, 3, 2);
//    graph.addEdge(3, 0, 3);

    AVL tree;
    tree.insert(90);
    tree.insert(80);
    tree.insert(70);
    tree.insert(85);
    tree.insert(82);
    tree.insert(86);
    tree.insert(100);
    tree.insert(50);
    tree.insert(20);




    clock_t start = clock();

    cout<<"Original Array:"<<endl;
//    Print::printArray(array, 6);
//    Print::printGraph(graph);
//    DijkstraPath a = ShortestPath::dijkstra(graph, 0);
//    Print::printVector(a.prevVertex);
//    Print::printVector(a.distance);

//    Print::printGraph(graph);
//    SpanningTree tree(graph);
//    Print::printGraph(tree);

//    vector<int> adjacent = graph.getAdjacentVertices(10);
//    Print::printVector(adjacent);
    Print::printBT(tree);
    cout<<endl;


//    double timeElapsed = double(clock()-start)/CLOCKS_PER_SEC * 1000;
//    cout<<"Time Elapsed: "<<fixed<<timeElapsed<<" ms"<<endl;
}

