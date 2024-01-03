//
// Created by ahsan on 12/3/23.
//

#ifndef CLION_ALGORITHM_H
#define CLION_ALGORITHM_H
#include <iostream>
#include "DataStructures.h"
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

// Re-declaration of data structures to resolve circular dependencies
class SinglyLinkedListNode;
class SinglyLinkedList;
class Queue;
class Stack;
class BTNode;
class BST;
struct Individual;
struct Vector2i;
class Graph;
class DirectedGraph;
class UndirectedGraph;
struct MinDistance;
class SpanningTree;
class BinaryTree;

class Sort
{
    static int Partition(int array[], int start, int end);
    static void bitonicMerge(int array[], int start, int length, int dir);
public:
    static void bubbleSort(int array[], int length);
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
    static void bitonicSort(int array[], int length, int start=0, int dir=0);
};

class ScreenColoring
{
    /*Supporting Functions*/

    // supporting function for flood fill
    static bool isValid(int **screen, int width, int height, int pixelX, int pixelY, int prevColor, int newColor);
public:
    static void floodFill(int **screen, int width, int height, int pixelX, int pixelY, int newColor);
};

class GeneticAlgorithms
{
    static const int POPULATION_SIZE = 100;
    static const string GENES;
public:
    static string naturalSelection(const string& target, int population_size = POPULATION_SIZE);
    static char mutatedGene();
    static Individual random_gnome(int size);
    static void sortOnWeakness(vector<Individual> &population);
};

class Chess
{
    static bool allVisited(int board[8][8]);
    static bool solveKnightTour(int solution[8][8], int x, int y, vector<Vector2i> moves);
    static bool isSafe(Vector2i& position);
public:
    static void printBoard(int board[8][8]);
    static void knightTour(int x, int y);
};

class Search
{
public:
    static bool breadthFirstSearch(Graph& graph, int startVertex, int endVertex);
    static bool depthFirstSearch(Graph& graph, int startVertex, int endVertex);
};

class ShortestPath
{
public:
    static MinDistance DijkstrasAlgorithm(Graph& graph, int vertex);
    static MinDistance BellmanFordAlgorithm(DirectedGraph& graph, int vertex);
    static vector<int> shortestPath(Graph& graph, int fromVertex, int toVertex);
    static int shortestDistance(Graph& graph, int fromVertex, int toVertex);
    static void shortestPaths(MinDistance minDistance, Graph &graph, int vertex);
    static UndirectedGraph KruskalAlgorithm(Graph& graph);
};

class Print
{
    static int printTree(BTNode *tree, int is_left, int offset, int depth, char s[][255]);
public:
    static void printArray(int array[], int length);
    static void printArray(int **array, int width, int height);
    static void printLinkedList(SinglyLinkedList& list);
    static void printQueue(Queue& queue);
    static void printStack(Stack& stack);
    static void printVector(vector<int>& list);
    static void printBT(BinaryTree &tree);
    static void printGraph(const Graph &graph);
    static void printGraph(const SpanningTree& graph);
};

#endif //CLION_ALGORITHM_H
