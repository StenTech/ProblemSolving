#include "heap.h"
#include <vector>
#include <bits/stdc++.h>

struct heap
{
    std::vector<int> data;

    heap() : data() {}

    int parent(int i) { return i  / 2; }
    int left(int i) { return 2 * i; }
    int right(int i) { return 2 * i + 1; }

};


heap myHeap = heap();




int getMax(){
    return myHeap.data[0];
}

int getSize(){
    return myHeap.data.size();
}

void insert(int element){
    myHeap.data.push_back(element);
    int i = getSize() - 1;
    int parent = myHeap.parent(i);
    while (i > 0 and myHeap.data[i] > myHeap.data[parent])
    {
        std::swap(myHeap.data[i], myHeap.data[parent]);
        i = parent;
        parent = myHeap.parent(i);
    }        
}

void removeMax(){
    myHeap.data[0] = myHeap.data[getSize() - 1];
    myHeap.data.pop_back();
    int i = 0;
    int left = myHeap.left(i);
    int right = myHeap.right(i);

    while(1) {
        int greatest = i;
        if (i < getSize() and myHeap.data[greatest] < myHeap.data[left]) {
            greatest = left;
        }
        if (i < getSize() and myHeap.data[greatest] < myHeap.data[right]) {
            greatest = right;
        }
        if (greatest == i) {
            break;
        }

        std::swap(myHeap.data[i], myHeap.data[greatest]);
        i = greatest;
        left = myHeap.left(i);
        right = myHeap.right(i);

    }
}

