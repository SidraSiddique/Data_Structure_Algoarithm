#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }
    void heapifyDown(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    int getMax() {
        return heap[0];
    }
    int extractMax() {
        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxValue;
    }
    int size() {
        return heap.size();
    }
    bool isEmpty() {
        return heap.empty();
    }
    void printHeap() {
        for (int i = 0 ; i < heap.size() ; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(30);
    maxHeap.insert(15);
    cout << "Heap elements after insertions: ";
    maxHeap.printHeap();
    cout << "Maximum element: " << maxHeap.getMax() << endl;
    cout << "Extracted maximum: " << maxHeap.extractMax() << endl;
    cout << "Heap elements after extracting max: ";
    maxHeap.printHeap();
    maxHeap.insert(25);
    maxHeap.insert(40);
    cout << "Heap elements after more insertions: ";
    maxHeap.printHeap();
    // Check heap size and if it is empty
    cout << "Heap size: " << maxHeap.size() << endl;
    cout << "Is heap empty? " << (maxHeap.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}

