//
// Created by ahsan on 12/3/23.
//

#include "DataStructures.h"

/*******************************************************************************************
 *                                                                                         *
 *                           Implementation of Array class                                 *
 *                                                                                         *
 *******************************************************************************************/

void Array::flipArray(int *array, int length, int i)
{
    i = (i==-1)?length-1:i;
    for(int j=0;true;j++, i--)
    {
        if(j==i || j+1==i)
            break;
        swap(array[j], array[i]);
    }
}

int Array::maxElement(const int *array, int length) {
    int max = array[0];
    for(int i=1;i<length;i++)
        if(array[i]>max)
            max = array[i];
    return max;
}

int Array::maxIndex(const int *array, int length) {
    int max = 0;
    for(int i=1;i<length;i++)
        if(array[i]>array[max])
            max = i;
    return max;
}

int Array::minIndex(const int *array, int length) {
    int min = 0;
    for(int i=1;i<length;i++)
        if(array[i]<array[min])
            min = i;
    return min;
}

void Array::sortedMerge(int *array, int start, int middle, int end) {
    int i=start,j=middle+1,k=0;
    int result[end-start+1];
    while(i<=middle && j<=end)
    {
        if(array[i]>array[j])
            result[k++] = array[j++];
        else
            result[k++] = array[i++];
    }

    while(i<=middle)
        result[k++] = array[i++];

    while(j<=end)
        result[k++] = array[j++];

    Array::copyArray(array, result, start, end);
}

void Array::copyArray(int *copiedTo, const int *copiedFrom, int fromIndex,int end) {
    for(int i=0;fromIndex<=end;i++)
        copiedTo[fromIndex++]=copiedFrom[i];
}

int Array::minElement(const int *array, int length) {
    int min = array[0];
    for(int i=1;i<length;i++)
        if(array[i]<min)
            min = array[i];
    return min;
}

void Array::shiftArray(int *array, int length, int start, int count, bool direction, int end) {
    if(end == 0)
        end = length-1;
    if(end<start)
        return;
    // direction=0 means shift left and direction=1 means shift right
    if(!direction)
    {
        if(start-count<0)
            return;
        for(int i=0;i<end-start+1;i++)
            Utility::swap(array[start+i], array[start-count+i]);
    }
    else
    {
        if(end+count>=length)
            return;
        for(int i=0;i<end-start+1;i++)
            Utility::swap(array[end-i], array[end+count-i]);
    }
}

/*******************************************************************************************
 *                                                                                         *
 *                           Implementation of Linked List class                           *
 *                                                                                         *
 *******************************************************************************************/

void SinglyLinkedList::pushBack(int data) {
    auto* q = new SinglyLinkedListNode(data);
    auto* dummy = new SinglyLinkedListNode();
    dummy->next = head;
    SinglyLinkedListNode* p = dummy;
    while(p->next!=nullptr)
        p=p->next;
    p->next = q;
    head = dummy->next;


}

int SinglyLinkedList::length() const {
    SinglyLinkedListNode* p = head;
    int c = 0;
    while(p!= nullptr)
    {
        p=p->next;
        c++;
    }
    return c;
}

/*******************************************************************************************
 *                                                                                         *
 *                           Implementation of Queue class                                 *
 *                                                                                         *
 *******************************************************************************************/

Queue::Queue(int size): capacity(size), front(size), rear(size)
{
    array = new int[capacity+1];
    for(int i=0;i<=capacity;i++)
        array[i]=0;
}

bool Queue::isEmpty() const {
    return front==rear;
}

bool Queue::isFull() const {
    return front==(rear+1)%(capacity+1);
}

void Queue::enqueue(int data) {
    if(!isFull())
    {
        rear = (rear+1)%(capacity+1);
        array[rear] = data;
    } else
        cout<<"Queue is Full!"<<endl;
}

int Queue::dequeue() {
    if(!isEmpty())
    {
        front = (front+1)%(capacity+1);
        return array[front];
    }
    else
    {
        cout<<"Queue is Empty!"<<endl;
        return -1;
    }
}

void Queue::operator=(Queue const& queue) {
    front = queue.front;
    rear = queue.rear;
    capacity = queue.capacity;
    delete[] array;
    array = new int[capacity+1];
    for(int i=0;i<=capacity;i++)
        array[i] = queue.array[i];
}

int Queue::getSize() {
    return capacity;
}


/*******************************************************************************************
 *                                                                                         *
 *                           Implementation of Utility class                               *
 *                                                                                         *
 *******************************************************************************************/

void Utility::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

/*******************************************************************************************
 *                                                                                         *
 *                           Implementation of Stack class                                 *
 *                                                                                         *
 *******************************************************************************************/

Stack::Stack(int size):top(-1), size(size), elements(0) {
    array = new int[size];
    for(int i=0;i<size;i++)
        array[i]=0;
}

bool Stack::isFull() const {
    return elements==size;
}

bool Stack::isEmpty() const {
    return elements==0;
}

void Stack::push(int data) {
    if(!isFull())
    {
        array[++top]=data;
        elements++;
    }
    else
        cout<<"Stack is full!"<<endl;
}

int Stack::pop() {
    if(!isEmpty())
    {
        elements--;
        return array[top--];
    }
    cout<<"Stack is empty!"<<endl;
    return -1;
}

int Stack::topElement() {
    if(!isEmpty())
        return array[top];
    cout<<"Stack is empty!"<<endl;
    return -1;
}

/*******************************************************************************************
 *                                                                                         *
 *                     Implementation of Binary Tree Node class                            *
 *                                                                                         *
 *******************************************************************************************/

BTNode::BTNode(int data) {
    this->data=data;
    left = nullptr;
    right = nullptr;
}

void BTNode::inOrder(BTNode *root) {
    if(root == nullptr)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int BTNode::maxDepth(BTNode *root) {
    if(root== nullptr)
        return 0;
    return 1+max(maxDepth(root->left), maxDepth(root->right));
}

void BTNode::preOrder(BTNode *root) {
    if(root == nullptr)
        return;
    cout<<root->data<<" ";
    inOrder(root->left);
    inOrder(root->right);
}

void BTNode::postOrder(BTNode *root) {
    if(root == nullptr)
        return;
    inOrder(root->left);
    inOrder(root->right);
    cout<<root->data<<" ";
}

/*******************************************************************************************
 *                                                                                         *
 *                     Implementation of Binary Search Tree class                          *
 *                                                                                         *
 *******************************************************************************************/

BST::BST(int data) {
    root = new BTNode(data);
}

BST::BST(BTNode *ref) {
    root=ref;
}

void BST::insert(int data) {
    auto* q = new BTNode(data);
    if(root == nullptr)
        root = q;
    else
    {
        BTNode* current = root;
        BTNode* parent = current;
        while(current!= nullptr)
        {
            parent = current;
            if(data>current->data)
                current=current->right;
            else
                current=current->left;
        }
        if(data>parent->data)
            parent->right=q;
        else
            parent->left=q;
    }
}

void BST::inOrder() {
    BTNode::inOrder(root);
    cout<<endl;
}

int BST::depth() {
    return BTNode::maxDepth(root);
}

void BST::print() {
    Print::printBT(root);
    cout<<endl;
}

void BST::preOrder() {
    BTNode::preOrder(root);
    cout<<endl;
}

void BST::postOrder() {
    BTNode::postOrder(root);
    cout<<endl;
}

void BST::remove(int data) {
    BTNode* current = root;
    BTNode* parent = nullptr;
    while(current!= nullptr)
    {
        if(current->data==data)
            break;
        parent = current;
        if(data>current->data)
            current=current->right;
        else
            current=current->left;
    }
    if(current== nullptr)
        cout<<"Node with data: "<<data<<" does exit in the BST!"<<endl;
    else
    {
        if(current->left== nullptr && current->right == nullptr)
        {
            if(current==root)
                delete root;
            else
            {
                if(current->data > parent->data)
                    parent->right= nullptr;
                else
                    parent->left= nullptr;
                delete current;
            }
        } else if (current->left== nullptr || current->right == nullptr)
        {
            if(current->right== nullptr)
            {
                if(current==root)
                {
                    BTNode* temp = root->left;
                    delete root;
                    root = temp;
                }
                else
                {
                    if(current->data>parent->data)
                        parent->right=current->left;
                    else
                        parent->left = current->left;
                    delete current;
                }
            }
            else
            {
                if(current==root)
                {
                    BTNode* temp = root->right;
                    delete root;
                    root = temp;
                }
                else
                {
                    if(current->data>parent->data)
                        parent->right=current->right;
                    else
                        parent->left = current->right;
                    delete current;
                }
            }
        }
        else
        {
            // when a node has both children
            BST leftSubtree(current->left);
            int replace = leftSubtree.max();
            if(current==root)
                root->data=replace;
            else
                current->data=replace;
            leftSubtree.remove(replace);
        }
    }
}

int BST::max() {
    BTNode* current = root;
    while(current->right!= nullptr)
        current=current->right;
    return current->data;
}

int BST::min() {
    BTNode* current = root;
    while(current->left!= nullptr)
        current=current->left;
    return current->data;
}

bool BST::search(int data) {
    BTNode* current = root;
    while(current!= nullptr)
    {
        if(current->data==data)
            return true;
        if(data>current->data)
            current=current->right;
        else
            current=current->left;
    }
    return false;
}

/*******************************************************************************************
 *                                                                                         *
 *                            Implementation of Heap class                                 *
 *                                                                                         *
 *******************************************************************************************/

Heap::Heap(int maxSize, const string& heapProperty):maxSize(maxSize), size(0) {
    property = heapProperty=="max";
    array = new int[maxSize];
    for(int i=0;i<maxSize;i++)
        array[i]=0;
}

Heap::Heap(int maxSize):maxSize(maxSize), size(0), property(true)
{
    array = new int[maxSize];
    for(int i=0;i<maxSize;i++)
        array[i]=0;
}

Heap::~Heap() {
    delete array;
}

void Heap::heapify(int root) {
    int left = 2*root;
    int right = 2*root+1;

    if(property)
    {
        int largest = root;
        if(array[left]>array[largest] && left<size)
            largest=left;
        if(array[right]>array[largest] && right<size)
            largest=right;
        if(largest!=root)
        {
            Utility::swap(array[root], array[largest]);
            heapify(largest);
        }

    } else
    {
        int smallest = root;
        if(array[left]<array[smallest] && left<size)
            smallest=left;
        if(array[right]<array[smallest] && right<size)
            smallest=right;
        if(smallest!=root)
        {
            Utility::swap(array[root], array[smallest]);
            heapify(smallest);
        }
    }
}

Heap::Heap(int maxSize, const string &heapProperty, int *array, int length):maxSize(maxSize), size(length) {
    property=heapProperty=="max";
    this->array = new int[maxSize];
    for(int i=0;i<length;i++)
        this->array[i+1] = array[i];
    createHeap();
}

void Heap::createHeap() {
    int index = size;
    while(index>0)
        heapify(index--);
}

void Heap::print() {
    Print::printArray(array+1, size);
}

/*******************************************************************************************
 *                                                                                         *
 *                        Implementation of Individual class                               *
 *                                                                                         *
 *******************************************************************************************/

Individual::Individual(string chromosome):chromosome(std::move(chromosome)) {
    weakness = 100;
}

int Individual::calculateWeakness(const string& target) {
    weakness=0;
    for(int i=0;i<target.length();i++)
        weakness += chromosome[i]!=target[i] ? 1 : 0;
    return weakness;
}

Individual Individual::mate(Individual i1, Individual i2) {
    Individual child;
    for(int i=0;i<i1.chromosome.size();i++)
    {
        int probability = rand()%100;
        if(probability<45)
            child.chromosome += i1.chromosome[i];
        else if(probability<90)
            child.chromosome += i2.chromosome[i];
        else
            child.chromosome += GeneticAlgorithms::mutatedGene();
    }
    return child;
}

void Individual::operator=(const Individual &other) {
    chromosome = other.chromosome;
    weakness = other.weakness;
}

/*******************************************************************************************
 *                                                                                         *
 *                           Implementation of Graph class                                 *
 *                                                                                         *
 *******************************************************************************************/

Graph::Graph(int size):maxVertices(size), numVertices(0) {
    vertices = new int[maxVertices];
    edges = new int*[maxVertices];
    for(int i=0;i<maxVertices;i++)
        edges[i] = new int[maxVertices];

    for(int i=0;i<maxVertices;i++)
    {
        vertices[i] = 0;
        for(int j=0;j<maxVertices;j++)
            edges[i][j] = NULL_EDGE;
    }
}

Graph::~Graph() {
    delete[] vertices;
    for(int i=0;i<maxVertices;i++)
        delete[] edges[i];
    delete[] edges;
}

bool Graph::isEmpty() const {
    return numVertices==0;
}

bool Graph::isFull() const {
    return numVertices==maxVertices;
}

bool Graph::isComplete() {
    for(int i=0;i<numVertices;i++)
        for(int j=0;j<numVertices;j++)
        {
            if(i==j)
                continue;
            if(edges[i][j]==NULL_EDGE)
                return false;
        }
    return true;
}

void Graph::addVertex(int data) {
    if(!isFull())
        vertices[numVertices++] = data;
    else
        cout<<"Graph is full!"<<endl;
}

void Graph::removeVertex(int data) {
    int position = hasIndex(data);
    if(position>=0)
    {
        vertices[position] = 0;
        Array::shiftArray(vertices, maxVertices, position+1, 1, 0, numVertices-1);
        for(int i=0;i<numVertices;i++)
        {
            edges[position][i] = NULL_EDGE;
            edges[i][position] = NULL_EDGE;
        }
        numVertices--;
    }
}

int Graph::hasIndex(int vertex) {
    for(int i=0;i<numVertices;i++)
        if(vertices[i]==vertex)
            return i;
    cout<<"No vertex with value: "<<vertex<<" found!"<<endl;
    return -1;
}

int Graph::weightIs(int vertex1, int vertex2) {
    int pos1 = hasIndex(vertex1);
    int pos2 = hasIndex(vertex2);
    if(pos1<0 || pos2<0)
        return -1;
    return edges[pos1][pos2];
}

bool Graph::isAdjacent(int vertex1, int vertex2) {
    return weightIs(vertex1, vertex2)>0;
}

int Graph::getVertices() const {
    return numVertices;
}

vector<int> Graph::getAdjacentVertices(int vertex) {
    int index = hasIndex(vertex);
    vector<int> v;
    for(int i=0;i<numVertices;i++)
    {
        if(edges[index][i]!=0)
            v.push_back(vertices[i]);
    }
    return v;
}

int Graph::getVertex(int index) {
    return vertices[index];
}

bool Graph::isConnected() {
    for(int i=0;i<numVertices;i++)
        for(int j=0;j<numVertices;j++)
            if(edges[i][j]!=0)
                if (!Search::breadthFirstSearch(*this, getVertex(i), getVertex(j)))
                    return false;
    return true;
}


/*******************************************************************************************
 *                                                                                         *
 *                         Implementation of Undirected class                              *
 *                                                                                         *
 *******************************************************************************************/

void UndirectedGraph::addEdge(int vertex1, int vertex2, int weight) {
    int pos1 = hasIndex(vertex1);
    int pos2 = hasIndex(vertex2);
    if(pos1<0 || pos2<0)
    {
        if (pos1 < 0)
            cout << "No such vertex with value: " << vertex1 << " found!" << endl;
        if (pos2 < 0)
            cout << "No such vertex with value: " << vertex2 << " found!" << endl;
    }
    else
    {
        edges[pos1][pos2] = weight;
        edges[pos2][pos1] = weight;
    }
}


/*******************************************************************************************
 *                                                                                         *
 *                     Implementation of Directed Graph class                              *
 *                                                                                         *
 *******************************************************************************************/

void DirectedGraph::addEdge(int vertex1, int vertex2, int weight) {
    int pos1 = hasIndex(vertex1);
    int pos2 = hasIndex(vertex2);
    if(pos1<0 || pos2<0)
    {
        if (pos1 < 0)
            cout << "No such vertex with value: " << vertex1 << " found!" << endl;
        if (pos2 < 0)
            cout << "No such vertex with value: " << vertex2 << " found!" << endl;
    }
    else
    {
        edges[pos1][pos2] = weight;
    }
}

SpanningTree::SpanningTree(Graph &graph): UndirectedGraph(graph.getVertices()) {
    if(graph.getVertices()>0)
    {
        for(int i=0;i<graph.getVertices();i++)
            vertices[i] = graph.vertices[i];
        numVertices = graph.numVertices;
        maxVertices = graph.maxVertices;
        vector<bool> visited;
        visited.reserve(graph.getVertices());
        for(int i=0;i<graph.getVertices();i++)
            visited.push_back(false);
        makeSpanningTree(graph, visited, 0);
    }
}

void SpanningTree::makeSpanningTree(Graph &graph, vector<bool> &visited, int start) {
    visited[start] = true;
    vector<int> adjacentVertices = graph.getAdjacentVertices(start);
    int startIndex = graph.hasIndex(start);
    for(auto &adjacent:adjacentVertices)
    {
        int adjacentIndex = graph.hasIndex(adjacent);
        if(!visited[graph.hasIndex(adjacent)])
        {
            UndirectedGraph::addEdge(start, adjacent, graph.edges[startIndex][adjacentIndex]);
            makeSpanningTree(graph, visited, adjacent);
        }
    }
}
