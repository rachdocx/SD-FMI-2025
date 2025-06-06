#include <iostream>
#include <algorithm> // pentru swap
using namespace std;

const int MAXDIM = 1000;

class MinHeap {
private:
    int h[MAXDIM];
    int dim_heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    // Urcare cheie (HEAP-UP)
    void upKey(int i) {
        while (i != 0 && h[parent(i)] > h[i]) {
            swap(h[i], h[parent(i)]);
            i = parent(i);
        }
    }

    // Coborare cheie (HEAPIFY)
    void downKey(int i) {
        while (left(i) < dim_heap) {
            int smallest = left(i);
            int r = right(i);

            if (r < dim_heap && h[r] < h[smallest])
                smallest = r;

            if (h[i] > h[smallest]) {
                swap(h[i], h[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }

public:
    // Constructor
    MinHeap() : dim_heap(0) {}

    // Inserare element in heap
    void insert(int x) {
        if (dim_heap >= MAXDIM) {
            cout << "Heap overflow!\n";
            return;
        }

        h[dim_heap] = x;
        upKey(dim_heap);
        dim_heap++;
    }

    // Returneaza minimul (radacina)
    int getMin() {
        if (dim_heap == 0) {
            cout << "Heap gol!\n";
            return -1;
        }
        return h[0];
    }

    // Extragere minim (HEAP-EXTRACT-MIN)
    void extractMin() {
        if (dim_heap == 0) {
            cout << "Heap gol!\n";
            return;
        }

        h[0] = h[dim_heap - 1];
        dim_heap--;
        if (dim_heap > 0) {
            downKey(0);
        }
    }

    // Afisare heap (pentru test)
    void printHeap() {
        for (int i = 0; i < dim_heap; ++i) {
            cout << h[i] << " ";
        }
        cout << "\n";
    }
};
int n,k,x;
int main() {
    MinHeap heap;

    return 0;
}
