// continuing ads project 1
// heap implementation

#include <iostream>

using namespace std;

class BinaryHeap {
    const static int MAX_SIZE = 32;

    int heap[MAX_SIZE];

    int size;

public:
	BinaryHeap();

    // returns the index of the parent node
    int parent(int i);

    // return the index of the left child
    int leftChild(int i);

    // return the index of the right child 
    int rightChild(int i);

    void swap(int *x, int *y);
    
    // insert the item at the appropriate position
    void insert(int data);

    // moves the item at position i of array a to its appropriate position
    void maxHeapify(int i);

    // returns the  maximum item of the heap
    int getMax();

    // deletes the max item and return
    int extractMax();

    // prints the heap
    void printHeap();

    // the sort we ve been waiting for
    int heapSort(int v[]);
};

BinaryHeap::BinaryHeap(){
        size = 0;
    }

int BinaryHeap::parent(int i) {
        return (i - 1) / 2;
    }

int BinaryHeap::leftChild(int i) {
        return 2*i + 1;
    }

int BinaryHeap::rightChild(int i) {
        return 2*i + 2;
    }

void BinaryHeap::swap(int *x, int *y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }

void BinaryHeap::insert(int data){
        if (size >= MAX_SIZE) {
            cout<<"The heap is full. Cannot insert"<<endl;
            return;
        }

        // first insert the time at the last position of the array 
        // and move it up
        heap[size] = data;
        size = size + 1;


        // move up until the heap property satisfies
        int i = size - 1;
        while (i != 0 && heap[BinaryHeap::parent(i)] < heap[i]) {
            BinaryHeap::swap(&heap[BinaryHeap::parent(i)], &heap[i]);
            i = BinaryHeap::parent(i);
        }
    }

void BinaryHeap::maxHeapify(int i){
        // find left child node
        int left = BinaryHeap::leftChild(i);

        // find right child node
        int right = BinaryHeap::rightChild(i);

        // find the largest among 3 nodes
        int largest = i;

        // check if the left node is larger than the current node
        if (left <= size && heap[left] > heap[largest]) {
            largest = left;
        }

        // check if the right node is larger than the current node 
        // and left node
        if (right <= size && heap[right] > heap[largest]) {
            largest = right;
        }

        // swap the largest node with the current node 
        // and repeat this process until the current node is larger than 
        // the right and the left node
        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            maxHeapify(largest);
        }

    }

int BinaryHeap::getMax() {
        return heap[0];
    }

int BinaryHeap::extractMax() {
        int maxItem = heap[0];

        // replace the first item with the last item
        heap[0] = heap[size - 1];
        size = size - 1;

        // maintain the heap property by heapifying the 
        // first item
        maxHeapify(0);
        return maxItem;
    }

void BinaryHeap::printHeap(){
        for (int i = 0; i < size; i++) {
            cout<<heap[i]<<' ';
        }
        cout<<endl;
    }

int BinaryHeap::heapSort(int v[]){
    int i = 0;
    while(size){
        v[i] = BinaryHeap::extractMax();     //haha lol
        i++;
    }
    return i;
}

//main
int main() {
    int v[32];
    BinaryHeap heap;
    heap.insert(7);
    heap.insert(5);
    heap.insert(2);
    heap.insert(4);
    heap.insert(11);
    heap.insert(13);
    cout << "Elements in the heap in the desired normal order: ";
    heap.printHeap();
    int k = heap.heapSort(v);
    cout << "\nElement from the heap in sorted order: ";
    for(int i = k-1; i >= 0; i--){
        cout << v[i] << ' ';
    }
    return 0;
}