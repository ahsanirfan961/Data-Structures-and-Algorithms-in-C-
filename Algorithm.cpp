//
// Created by ahsan on 12/3/23.
//
#include "Algorithm.h"
#include <cmath>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <utility>

/* Implementation of whole sort class*/
void Sort::bubbleSort(int *array, int length) {
    for(int i=0;i<length;i++)
        for(int j=0;j<length-i-1;j++)
        {
            if(array[j]>array[j+1])
                Utility::swap(array[j], array[j+1]);
        }
}

void Sort::bubbleSort(SinglyLinkedList &list) {
    SinglyLinkedListNode* p = list.head;
    while(p!= nullptr)
    {
        SinglyLinkedListNode* q = p->next;
        while (q!= nullptr)
        {
            if(q->data<p->data)
                Utility::swap(p->data, q->data);
            q=q->next;
        }
        p=p->next;
    }
}

void Sort::cycleSort(int *array, int length) {
    for(int cycleStart = 0; cycleStart<length-1; cycleStart++)
    {
        int temp = array[cycleStart];
        while(true){
            int pos = cycleStart;
            for (int i = pos+1; i < length; i++)
                if (array[i] < temp)
                    pos++;
            if (pos == cycleStart)
                break;
            while (array[pos] == temp)
                pos++;
            Utility::swap(array[pos], temp);
        }
        array[cycleStart] = temp;
    }
}

void Sort::pancakeSort(int *array, int length) {
    for(int i=0;i<length-1;i++)
    {
        Array::flipArray(array, length, Array::maxIndex(array, length-i));
        Array::flipArray(array, length, length - 1 - i);
    }
}

void Sort::mergeSort(int *array, int length, int start, int end) { // NOLINT(*-no-recursion)
    end =(end==-1)?length-1:end;
    if(start==end)
        return;
    int middle = (start+end)/2;
    mergeSort(array, middle+1, start, middle);
    mergeSort(array, length-middle-1, middle+1, end);
    Array::sortedMerge(array, start, middle, end);
}

void Sort::quickSort(int *array, int length, int start, int end) { // NOLINT(*-no-recursion)
    end = (end==-9)?length-1:end;

    if(start<end)
    {
        int p_index = Partition(array, start, end);
        quickSort(array, length, start, p_index-1);
        quickSort(array, length, p_index+1, end);
    }
}

int Sort::Partition(int *array, int start, int end) {
    int pivot = array[end];
    int p_index = start;

    for(int i=start;i<end;i++)
    {
        if(array[i]<=pivot)
        {
            Utility::swap(array[i], array[p_index]);
            p_index++;
        }
    }
    Utility::swap(array[p_index], array[end]);
    return p_index;
}

void Sort::insertionSort(int *array, int length) {
    for(int i=1;i<length;i++)
    {
        int key = array[i];
        int j = i-1;
        while(j>=0 && array[j]>key)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void Sort::selectionSort(int *array, int length) {
    for(int i=0;i<length-1;i++)
    {
        int* subArray = array + i;
        Utility::swap(array[i], array[Array::minIndex(subArray, length-i)+i]);
    }
}

void Sort::bucketSort(int *array, int length) {
    const int nBuckets = 10;
    const int min = Array::minElement(array, length);
    const int max = Array::maxElement(array, length);
    const int range = ceil((double)(max - min)/nBuckets);
    SinglyLinkedList bucket[nBuckets];

    for(int i=0;i<length;i++)
        bucket[(array[i]-min)/range].pushBack(array[i]);

    for(auto & i : bucket)
        Sort::bubbleSort(i);

    int j=0;
    for(auto & i : bucket)
    {
        SinglyLinkedListNode* p = i.head->next;
        while(p!= nullptr)
        {
            array[j++] = p->data;
            p=p->next;
        }
    }

}

void Sort::countingSort(int *array, int length) {
    const int max = Array::maxElement(array, length);
    int count[max+1];
    for(int& i : count)
        i = 0;
    for(int i=0;i<length;i++)
        count[array[i]]++;

    for(int i=0, j=0;i<=max;)
    {
        if(count[i]>0)
        {
            array[j++] = i;
            count[i]--;
        }

        else
            i++;
    }

}

void Sort::gnomeSort(int *array, int length) {
    int index = 0;
    while(index<length)
    {
        if(index==0)
            index++;
        if(array[index]>=array[index-1])
            index++;
        else
        {
            Utility::swap(array[index], array[index-1]);
            index--;
        }
    }
}

void Sort::pigeonHoleSort(int *array, int length) {
    const int min = Array::minElement(array, length);
    const int max = Array::maxElement(array, length);
    const int range = max-min+1;

    // making array of (queues of size 10) of size range
    auto* holes = new Queue[range];
    for(int i=0;i<range;i++)
        holes[i] = Queue(10);

    for(int i=0;i<length;i++)
        holes[array[i]-min].enqueue(array[i]);

    for(int i=0, k=0;i<range;i++)
    {
        while(!holes[i].isEmpty())
            array[k++] = holes[i].dequeue();
    }
}

void Sort::bitonicSort(int *array, int length, int start, int dir) {
    /* check if the log2(length) is a whole number else return*/
    double temp = log2(length);
    int temp2 = temp;
    if(temp-temp2 != 0)
    {
        cout<<"The number of elements for bitonic sort must be of order 2^n"<<endl;
        return;
    }

    if(length>1)
    {
        int middle = length/2;
        bitonicSort(array, middle, start, 0);
        bitonicSort(array, middle, start+middle, 1);

        bitonicMerge(array, start, length, dir);
    }
}

void Sort::bitonicMerge(int *array, int start, int length, int dir) {
    if(length>1)
    {
        int middle = length/2;
        for(int i=start;i<start+middle;i++)
        {
            if(dir==(array[i]<array[i+middle]))
                Utility::swap(array[i], array[i+middle]);
        }
        bitonicMerge(array, start, middle, dir);
        bitonicMerge(array, start+middle, middle, dir);
    }
}

/* Implementation of Print Class*/

void Print::printArray(int *array, int length) {
    for(int i=0;i<length;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

void Print::printLinkedList(SinglyLinkedList& list) {
    SinglyLinkedListNode* p = list.head;
    while(p != nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void Print::printQueue(Queue& queue) {
    Queue temp(queue.getSize());
    temp = queue;
    while(!temp.isEmpty())
        cout<<temp.dequeue()<<" ";
    cout<<endl;
}

void Print::printArray(int **array, int width, int height) {
    for(int i=0;i<width;i++)
    {
        for(int j=0;j<height;j++)
            cout<<array[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void Print::printStack(Stack &stack) {
    for(int i=0;i<=stack.top;i++)
        cout<<stack.array[i]<<" ";
    cout<<endl;
}

void Print::printVector(vector<int> &list) {
    for(auto& i:list)
        cout<<i<<" ";
    cout<<endl;
}

void Print::printBT(BTNode *root)
{
    char s[BTNode::maxDepth(root)*2][255];
    for (auto & i : s)
        sprintf(i, "%80s", " ");

    printTree(root, 0, 0, 0, s);

    for (auto & i : s)
        printf("%s\n", i);
}

int Print::printTree(BTNode *tree, int is_left, int offset, int depth, char s[][255])
{
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%03d)", tree->data);

    int left  = printTree(tree->left, 1, offset, depth + 1, s);
    int right = printTree(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}



// Implementation of Screen Coloring Class

void ScreenColoring::floodFill(int **screen, int width, int height, int pixelX, int pixelY, int newColor) {
    queue<Vector2i> toFill;
    Vector2i parent(pixelX, pixelY);
    int prevColor = screen[pixelX][pixelY];

    toFill.push(parent);

    while(!toFill.empty())
    {
        Vector2i current = toFill.front();
        toFill.pop();

        screen[current.x][current.y] = newColor;

        if (isValid(screen, width, height, current.x + 1, current.y, prevColor, newColor))
            toFill.push(Vector2i(current.x + 1, current.y));

        if (isValid(screen, width, height, current.x - 1, current.y, prevColor, newColor))
            toFill.push(Vector2i(current.x - 1, current.y));

        if (isValid(screen, width, height, current.x, current.y + 1, prevColor, newColor))
            toFill.push(Vector2i(current.x, current.y + 1));

        if (isValid(screen, width, height, current.x, current.y - 1, prevColor, newColor))
            toFill.push(Vector2i(current.x, current.y - 1));

    }
}

bool ScreenColoring::isValid(int **screen, int width, int height, int pixelX, int pixelY, int prevColor, int newColor) {

    if(pixelX<0 || pixelX>=width || pixelY<0 || pixelY>=height || screen[pixelX][pixelY]==newColor || screen[pixelX][pixelY]!=prevColor)
        return false;
    return true;
}

// Implementation of Genetic Algorithms
const string GeneticAlgorithms::GENES = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890, .-;:_!\"#%&/()=?@${[]}";
string GeneticAlgorithms::naturalSelection(const string& target, int population_size) {
    srand(time(nullptr));
    int generation = 0;
    vector<Individual> population;
    for(int i=0;i<population_size;i++)
        population.push_back(random_gnome(target.size()));

    bool found = false;
    while(!found)
    {
        for(auto & i : population)
            i.calculateWeakness(target);
        sortOnWeakness(population);
        if(population[0].weakness <= 0)
        {
            found= true;
            break;
        }
        vector<Individual> nextGeneration;
        int fittest = (10*population_size)/100;
        for(int i=0;i<fittest;i++)
            nextGeneration.push_back(population[i]);

        int childs = (90*population_size)/100;
        for(int i=0;i<childs;i++)
        {
            int father = rand()%50;
            int mother = rand()%50;
            Individual child = Individual::mate(population[father], population[mother]);
            child.calculateWeakness(target);
            nextGeneration.push_back(child);
        }
        population = nextGeneration;
        cout<< "Generation: " << generation << "\t";
        cout<< "String: "<< population[0].chromosome <<"\t";
        cout<< "Weakness: "<< population[0].weakness << "\n";
        generation++;
    }
    cout<< "Generation: " << generation << "\t";
    cout<< "String: "<< population[0].chromosome <<"\t";
    cout<< "Weakness: "<< population[0].weakness << "\n";
    return population[0].chromosome;
}

Individual GeneticAlgorithms::random_gnome(int size) {
    Individual person;
    for(int i=0;i<size;i++)
        person.chromosome += mutatedGene();
    return person;
}

char GeneticAlgorithms::mutatedGene() {
    char gene = GENES[rand()%GENES.size()];
    return gene;
}

void GeneticAlgorithms::sortOnWeakness(vector<Individual> &population) {
    for(int i=0;i<population.size();i++)
        for(int j=0;j<population.size()-i-1;j++)
        {
            if(population[j].weakness>population[j+1].weakness)
            {
                Individual temp = population[j];
                population[j] = population[j+1];
                population[j+1] = temp;
            }
        }
}



