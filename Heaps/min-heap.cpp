#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;
int heap[maxn];
int sz = 0;

int getParent(int index){ return (index - 1)/2;}
int getLeftChild(int index){ return (index * 2) + 1;}
int getRightChild(int index){ return (index * 2) + 2;}

bool hasParent(int index){ return getParent(index) >= 0;}
bool hasLeftChild(int index){ return getLeftChild(index) < sz; }
bool hasRightChild(int index){ return getRightChild(index) < sz; }

bool isEmpty(){ return sz == 0; }
int getMin(){ return heap[0]; }

void swap(int parent, int child){
    int temp = heap[parent];
    heap[parent] = heap[child];
    heap[child] = temp;
}

void insert(int value){
    int index = sz;
    heap[index] = value;
    ++sz;
    while(hasParent(index) && heap[getParent(index)] > heap[index]){
        swap(getParent(index), index);
        index = getParent(index);
    }
}

int erase(){
    int index = 0, minChild;
    int value = heap[0];
    heap[0] = heap[sz - 1];
    --sz;
    while(hasLeftChild(index)){
        minChild = getLeftChild(index);
        if(hasRightChild(index) && heap[getRightChild(index)] < heap[minChild]){
            minChild = getRightChild(index);
        }
        if(heap[minChild] < heap[index]){
            swap(index, minChild);
        }else{
            break;
        }
        index = minChild;
    }
    return value;
}

int main(){
    int number;

    for(int i = 0; i < 10; i++){
        scanf("%d",&number);
        insert(number);
    }

    while(!isEmpty()){
        printf("%d\n",erase());
    }
    
    return 0;
}