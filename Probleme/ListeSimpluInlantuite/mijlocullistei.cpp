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
    Node * pred = nullptr;
    bool ok =0;
    while (p!=nullptr) {
        if (p->info == x) {
            ok = 1;
            break;
        }
        pred=p;
        p=p->next;
    }
    if (!ok) {
         cout<<"Nu exista in lista";
    }else if (pred == nullptr) {
        head=head->next;
    }
    else {
        Node * succesor = p->next;
        pred->next= succesor;
    }
}
int getSize() {
    int nr = 0;
    Node * p = head;
    while (p!=nullptr) {
        nr++;
        p=p->next;
    }
    return nr;
}
int getNthNode(int n) {
    int i =0;
    Node * p = head;
    while (p!=nullptr) {
        i++;
        if (i==n)
            break;
        p=p->next;
    }
    return p->info;
}
int main() {
    for (int i=1;i<=11;++i)
        adaugareFinal(i);
    cout<<getNthNode(getSize()/2+1);
    return 0;
}
