//
// Created by ahsan on 12/3/23.
//

#ifndef DATA_STRUCTURES___ALGORITHMS_DATASTRUCTURES_H
#define DATA_STRUCTURES___ALGORITHMS_DATASTRUCTURES_H
#include <bits/stdc++.h>
#include "Algorithm.h"

using namespace std;

class Array
{
public:
    static void flipArray(int array[], int length, int i=-1);
    static int maxElement(const int array[], int length);
    static int minElement(const int array[], int length);
    static int maxIndex(const int array[], int length);
    static int minIndex(const int array[], int length);
    static void sortedMerge(int array1[], int start, int middle, int end);
    static void copyArray(int *copiedTo, const int *copiedFrom, int fromIndex, int end);
    static void shiftArray(int *array, int length, int start, int count, bool direction, int end=0);
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

// Stack Data Structure
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

struct BTNode
{
    int data;
    BTNode* left;
    BTNode* right;

    BTNode():data(0), left(nullptr), right(nullptr){}
    explicit BTNode(int data);
};

class BinaryTree
{
protected:
    BTNode* root;
    friend class Print;
public:
    BinaryTree():root(nullptr){}
    explicit BinaryTree(BTNode* root):root(root){}
    explicit BinaryTree(int data);
    virtual ~BinaryTree()= default;
    BTNode* getRoot();
    virtual void insert(int data);
    virtual void remove(int data);
    void inOrder();
    void preOrder();
    void postOrder();
    int height();
};

class BST : public BinaryTree
{
protected:
    explicit BST(BTNode* ref);
public:
    BST():BinaryTree(){}
    explicit BST(int data);
    explicit BST(BinaryTree& tree);
    ~BST() override =default;
    void insert(int data) override;
    void remove(int data) override;
    int max();
    int min();
    bool search(int data);
};

class AVL : public BST
{
    explicit AVL(BTNode* ref);
    BTNode *leftRotate();
    BTNode *rightRotate();
    void balance();
public:
    AVL():BST(){}
    explicit AVL(int data);
    ~AVL() override=default;
    int getBalanceFactor();
    bool isBalanced();
    void insert(int data) override;
    void remove(int data) override;
};

class Heap
{
    // Heap property: Max heap(true) or Min Heap(false)
    bool property;
    int *array;
    int size;
    int maxSize;
public:
    explicit Heap(int maxSize);
    Heap(int maxSize, const string& heapProperty);
    Heap(int maxSize, const string& heapProperty, int* array, int length);
    ~Heap();
    void heapify(int root);
    void createHeap();
    void print();
};

// Supporting data type for Genetic Algorithms
class Individual
{
public:
    string chromosome;
    int weakness;
    Individual():weakness(100){}
    explicit Individual(string chromosome);
    int calculateWeakness(const string& target);
    static Individual mate(Individual i1, Individual i2);
    void operator=(const Individual& other);
};

class Graph
{
    friend class Print;
    friend class ShortestPath;
    friend class SpanningTree;
protected:
    int *vertices;
    int **edges;
    int maxVertices;
    int numVertices;
public:
    static const short NULL_EDGE = 0;
    static const short INF_EDGE = 9999;
    explicit Graph(int size);
    virtual ~Graph();
    bool isEmpty() const;
    bool isFull() const;
    bool isComplete();
    void addVertex(int data);
    void removeVertex(int data);
    virtual void addEdge(int vertex1, int vertex2, int weight)=0;
    int weightIs(int vertex1, int vertex2);
    int hasIndex(int vertex);
    bool isAdjacent(int vertex1, int vertex2);
    int getVertices() const;
    vector<int> getAdjacentVertices(int vertex);
    int getVertex(int index);
    bool isConnected();
};

class UndirectedGraph : public Graph
{
    friend class MinimumSpanningTree;
public:
    explicit UndirectedGraph(int size): Graph(size){}
    ~UndirectedGraph() override= default;
    void addEdge(int vertex1, int vertex2, int weight=1) override;
};

class DirectedGraph : public Graph
{
public:
    explicit DirectedGraph(int size): Graph(size){}
    ~DirectedGraph() override= default;
    void addEdge(int vertex1, int vertex2, int weight=1) override;
};

struct MinDistance
{
    // the indexes of these arrays represent the indexes of vertices of the graph
    // and the values in prevVertex represent the index of their previous vertices
    vector<int> prevVertex;
    vector<int> distance;
};

class SpanningTree : protected UndirectedGraph
{
    friend class Print;
    void makeSpanningTree(Graph& graph, vector<bool> &visited, int start);
public:
    explicit SpanningTree(Graph& graph);
    ~SpanningTree() override = default;
};

class MinimumSpanningTree : public SpanningTree
{
public:
    explicit MinimumSpanningTree(Graph& graph);
    ~MinimumSpanningTree() override=default;
};

class DisjointSetUnion
{
    int *parent;
    int *rank;
public:
    explicit DisjointSetUnion(int length);
    int findSet(int vertex);
    void unionSets(int vertex1, int vertex2);
};

class Utility
{
public:
    static void swap(int& a, int& b);
};

#endif //DATA_STRUCTURES___ALGORITHMS_DATASTRUCTURES_H
