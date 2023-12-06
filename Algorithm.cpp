//
// Created by ahsan on 12/3/23.
//
#include "Algorithm.h"
#include <cmath>

/* Implementation of whole sort class*/

void Sort::bubbleSort(int *array, int length) {
    for(int i=0;i<length;i++)
        for(int j=0;j<length-i-1;j++)
        {
            if(array[j]>array[j+1])
                Utility::swap(array[j], array[j+1]);
        }
}

void Sort::bubbleSort(SinglyLinkedListNode &list) {
    SinglyLinkedListNode* p = &list;
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
    SinglyLinkedListNode bucket[nBuckets];

    for(int i=0;i<length;i++)
        SinglyLinkedListNode::pushBack(&bucket[(array[i]-min)/range], array[i]);

    for(auto & i : bucket)
        Sort::bubbleSort(i);

    int j=0;
    for(auto & i : bucket)
    {
        SinglyLinkedListNode* p = i.next;
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

/* Implementation of Print Class*/

void Print::printArray(int *array, int length) {
    for(int i=0;i<length;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

void Print::printLinkedList(SinglyLinkedListNode& head) {
    SinglyLinkedListNode* p = &head;
    while(p != nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

