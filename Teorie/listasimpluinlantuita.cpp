#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *next;
};

Node *head = nullptr;
Node *last = nullptr;

void adaugareInceput(int x) {
    Node *p = new Node;
    p->next = nullptr;
    p->info = x;
    if (head == nullptr)
        head = last = p;
    else {
        p->next = head;
        head = p;
    }
}

void adaugaFinal(int x) {
    Node *p = new Node;
    p->next = nullptr;
    p->info = x;
    if (head == nullptr)
        head = last = p;
    else {
        last->next = p;
        last = p;
    }
}

void stergere(int x) {
    Node *p = head;
    Node *pred = nullptr;
    bool ok = 0;
    while (p != nullptr) {
        if (p->info == x) {
            ok = 1;
            break;
        }
        pred = p;
        p = p->next;
    }
    if (!ok)
        cout << "Nu exista in lista";
    else if (pred == nullptr)
        head = head->next;
    else {
        Node *succ = p->next;
        pred->next = succ;
    }
}

void parcurgere() {
    Node *p = head;
    while (p != nullptr) {
        cout << p->info << " ";
        p = p->next;
    }
}
int main() {
    for(int i = 1; i <= 10; i++) {
        adaugaFinal(i);
    }
    stergere(10);
    parcurgere();
    return 0;
}