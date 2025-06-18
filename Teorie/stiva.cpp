#include <iostream>
using namespace std;

struct Stiva {
    string nume;
    Stiva *next;
};
void push(Stiva *&vf, string x) {
    Stiva *t = new Stiva;
    t->nume = x;
    t->next = vf;
    vf = t;
}
void pop(Stiva * &vf) {
    if (vf == NULL)
        return;
    vf = vf->next;
}

string top(Stiva *vf) {
    return vf->nume;
}
bool este_vida(Stiva *vf) {
    return vf == NULL;
}
int main()
{
    Stiva * vf = nullptr;
    push(vf,"10");
    cout<<top(vf);
    return 0;
}

