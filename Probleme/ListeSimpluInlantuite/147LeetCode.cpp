#include <iostream>
#include <fstream>
using namespace std;
struct Node {
    int info;
    Node * next;
};
Node * last = nullptr;
Node * head = nullptr;
void adaugareInceput(int x) {
    Node * p = new Node;
    p->next=nullptr;
    p->info = x;
    if (head == nullptr) {
        head=last=p;
    }
    else {
        p->next = head;
        head=p;
    }
}
void adaugareFinal(int x) {
    Node * p = new Node;
    p->next = nullptr;
    p->info = x;
    if (head == nullptr) {
        head=last=p;
    }
    else {
        last->next=p;
        last = p;
    }
}
void parcurgere() {
    Node * p = head;
    while (p != nullptr) {
        cout<<p->info<<" ";
        p=p->next;
    }
}
void stergere (int x) {
    Node * p = head;
    Node * pred = nullptr;
    bool ok = 0;
    while (p!=nullptr) {
        if (p->info == x) {
            ok=1;
            break;
        }
        pred = p;
        p=p->next;
    }
    if (!ok)
        cout<<"Elementul nu exista in lista";
    else {
        if (pred == nullptr) {
            head = head->next;
        }
        else {
            Node * succesor =p->next;
            pred->next= succesor;
        }
    }
}
int n,x;
int main() {
    cin >>n;
    for (int i=1;i<=n;++i) {
        cin>>x;
        adaugareInceput(x);
    }
    Node * p = head;
    while (p !=nullptr) {
        Node * q = p->next;
        while (q != nullptr) {
            if (p->info >= q->info)
                swap(p->info,q->info);
            q=q->next;
        }
        p=p->next;
    }
    parcurgere();
    return 0;
}
