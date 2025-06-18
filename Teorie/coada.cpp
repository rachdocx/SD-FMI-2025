#include <iostream>

using namespace std;

struct Node {
    int info;
    Node *next;
};

Node *head = nullptr;
Node *last = nullptr;

void adauga(int x) {
    Node *p = new Node;
    p->info = x;
    p->next = nullptr;

    if (head == nullptr)
        head = last = p;
    else {
        last->next = p;
        last = p;
    }
}

void parcurge() {
    Node *p = head;
    while (p != nullptr) {
        cout << p->info << " ";
        p = p->next;
    }
}

void stergere() {
    if (head == nullptr)
        return;
    head = head->next;
    if (head == nullptr)
        last = nullptr;
}

int main()
{for(int i=1;i<=10;++i)
    adauga(i);
    stergere();
    parcurge();
    return 0;
}