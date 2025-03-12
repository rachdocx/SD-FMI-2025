#include <iostream>
#include <vector>
using namespace std;


struct Nod {
    int val;
    Nod* next;
};


void push(Nod*& top, int val) {
    Nod* nou = new Nod;
    nou->val = val;
    nou->next = top;
    top = nou;
}


void pop(Nod*& top) {
    if (top == nullptr) return;
    Nod* temp = top;
    top = top->next;
    delete temp;
}


int top(Nod* top) {
    if (top == nullptr) return -1;
    return top->val;
}

bool empty(Nod* top) {
    return top == nullptr;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), result(n, -1);
    Nod* st = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        while (!empty(st) && arr[top(st)] < arr[i]) {
            result[top(st)] = arr[i];
            pop(st);
        }
        push(st, i);
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
