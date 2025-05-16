#ifndef HEAP_H
#define HEAP_H
#include <ranges>

class MinHeap {
public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        size = 0;
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];

        for (int i = 0; i < capacity; i++) { //initialize position to -1
            position[i] = -1;
        }
    }

    ~MinHeap() {
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    }

    void insert(int vertex, int key) {
        if (size == capacity)
            return;

        int i = size; //insert at end
        heapArray[i] = vertex;
        keyArray[vertex] = key;
        position[vertex] = i;

        size++;

        while (i > 0 && keyArray[heapArray[parent(i)]] > keyArray[heapArray[i]]) { //fix min heap property
            position[heapArray[i]] = parent(i); //update position
            position[heapArray[parent(i)]] = i;

            int temp = heapArray[i]; //swap vertices
            heapArray[i] = heapArray[parent(i)];
            heapArray[parent(i)] = temp;

            i = parent(i); //move to parent
        }
    }

    int extractMin() {
        if (isEmpty())
            return -1;

        int root = heapArray[0]; //store minimum vertex
        heapArray[0] = heapArray[size - 1]; //replace root with last vertex
        position[heapArray[0]] = 0; //update position of last vertex
        position[root] = -1; //mark extracted vertex as not in heap

        --size;

        if (!isEmpty()) //heapify root
            minHeapify(0);
        return root;
    }

    void decreaseKey(int vertex, int newKey) {
        int i = position[vertex]; //get index of vertex in heap array

        keyArray[vertex] = newKey; //update key value

        while (i > 0 && keyArray[heapArray[parent(i)]] > keyArray[heapArray[i]]) { //fix mean heap property
            position[heapArray[i]] = parent(i); //update position
            position[heapArray[parent(i)]] = 1;

            int temp = heapArray[i]; //swap vertices
            heapArray[i] = heapArray[parent(i)];
            heapArray[parent(i)] = temp;

            i = parent(i); //move to parent
        }
    }

    bool isInMinHeap(int vertex) {
        return position[vertex] != -1;
    }

    bool isEmpty() {
        return size == 0;
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    int parent(int i) { return (i - 1) / 2;}

    void minHeapify(int idx) {
        int smallest = idx;
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;

        if (l < size && keyArray[heapArray[l]] < keyArray[heapArray[smallest]]) //find smallest
            smallest = l;
        if (r < size && keyArray[heapArray[r]] < keyArray[heapArray[smallest]])
            smallest = r;

        if (smallest != idx) { //if idx is not smallest, swap and continue
            position[heapArray[idx]] = smallest; //update position
            position[heapArray[smallest]] = idx;

            int temp = heapArray[idx]; //swap vertices
            heapArray[idx] = heapArray[smallest];
            heapArray[smallest] = temp;

            minHeapify(smallest); //recursive call
        }
    }
};

#endif