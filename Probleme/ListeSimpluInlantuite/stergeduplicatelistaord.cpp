#include <iostream>
#include <fstream>
using namespace std;
struct Node {
    int info;
    Node * next;
};
Node * head = nullptr;
Node * last = nullptr;
void adaugareInceput(int x) {
    Node * p = new Node;
    p->info = x;
    p->next = nullptr;
    if (head == nullptr)
        head=last=p;
    else {
        p->next = head;
        head = p;
    }
}
void adaugareFinal(int x) {
    Node * p = new Node;
    p->info = x;
    p->next = nullptr;
    if (head == nullptr)
        head = last =p;
    else {
        last->next = p;
        last = p;
    }
}
void stergere(int x) {
    Node * p = head;
    Node * predecesor = nullptr;
    bool ok =0;
    while (p != nullptr) {
        if (p->info == x) {
            ok=1;
            break;
        }
        predecesor = p;
        p = p->next;
    }
    if (!ok)
        cout<<"NU";
    else
        if (predecesor == nullptr) {
            head = head->next;
        }
    else {
        Node * succesor = p->next;
        predecesor -> next = succesor;
    }
}
void parcurgere() {
    Node * p = head;
    while (p!=nullptr) {
        cout<<p->info;
        p=p->next;
    }
}
void stergeduplicate() {
    Node * p = head;
    while (p->next!=nullptr) {
        if (p->info==p->next->info) {
            stergere(p->info);
        }
        p=p->next;
    }
}
int main() {
    adaugareInceput(1);
    adaugareInceput(1);
    adaugareInceput(2);
    adaugareInceput(3);
    adaugareInceput(3);
    adaugareInceput(3);
   stergeduplicate();
    parcurgere();
    return 0;
}
