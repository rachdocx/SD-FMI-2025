#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    char info;
    Node *next;
};

void push(Node *&top, char c) {
    Node *p = new Node;
    p->info = c;
    p->next = top;
    top = p;
}

void pop(Node *&top) {
    if (top == nullptr)
        return;
    else {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

char peek(Node *&top) {
    if (top == nullptr)
        return 0;
    return top->info;
}

bool empty(Node *&top) {
    return top == nullptr;
}
int main() {
    string sir;
    cin>>sir;
    Node * s = nullptr;
    for (auto i:sir) {
        if (i == '(' || i == '['||i=='{')
            push(s,i);
        if (i== ')' && peek(s) == '(')
            pop(s);
        if (i== ']' && peek(s) == '[')
           pop(s);
        if (i== '}' && peek(s) == '{')
            pop(s);
    }
    if (empty(s))
        cout<<"DA";
    else
        cout<<"NU";
    return 0;
}
