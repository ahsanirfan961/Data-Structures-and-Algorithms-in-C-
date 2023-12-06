//
// Created by ahsan on 12/3/23.
//

#include "DataStructures.h"

// Implementation of Array Class

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

int Array::minIndex(int *array, int length) {
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

// Implementation of Linked List Class

void SinglyLinkedListNode::pushBack(SinglyLinkedListNode* head, int data) {
    auto* q = new SinglyLinkedListNode(data);
    auto* dummy = new SinglyLinkedListNode();
    dummy->next = head;
    SinglyLinkedListNode* p = dummy;
    while(p->next!=nullptr)
        p=p->next;
    p->next = q;
    head = dummy->next;
}

// Implementation of Utilities Class

void Utility::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}