#include <iostream>
#include <fstream>
using namespace std;

struct nod {
    int info;
    nod* next;
};

void push(nod*& top, int x) {
    nod* nou = new nod;
    nou->info = x;
    nou->next = top;
    top = nou;
}

void pop(nod*& top) {
    if (top == nullptr) {
        return;
    }
    nod* temp = top;
    top = top->next;
    delete temp;
}

int peek(nod*& top) {
    if (top == nullptr) {
        return 0;
    }
    return top->info;
}

bool empty(nod*& top) {
    return top == nullptr;
}

int main() {
    nod * s1 =nullptr;
    push(s1,7);
    cout<<peek(s1);
    push(s1,6);
    cout<<peek(s1);
    pop(s1);
    cout<<peek(s1);
    return 0;
}
