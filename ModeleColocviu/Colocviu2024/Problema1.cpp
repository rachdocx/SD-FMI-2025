#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Nod {
public:
    string comanda, argument;
    Nod * next;
    Nod(string comanda = "", string argument="", Nod * next=nullptr) {
        this->comanda=comanda;
        this->argument=argument;
        this->next=next;
    }
};
class Stiva {
private:
    Nod * varf;
public:
    Stiva() {
        this->varf = nullptr;
    }
    ~Stiva() {
        while (!empty()) {
            pop();
        }
    }
    void push(string comanda, string argument="") {
        Nod * newNod = new Nod(comanda,argument,varf);
        varf=newNod;
    }
    void pop() {
        if (empty()) {
            cout<<"Stiva este goala!\n";
            return;
        }
        Nod * delNod = varf;
        varf = varf->next;
        delete delNod;
    }
    string topComanda() {
        if (empty()) {
            cout<<"Stiva este goala!\n";
            return "";
        }
        else
            return varf->comanda;
    }
    string topArgument() {
        if (empty()) {
            cout<<"Stiva este goala!\n";
            return "";
        }
        else
            return varf->argument;
    }
    bool empty() {
        return varf == nullptr;
    }
};
int n,i;
string argument, comanda;
int main() {
    Stiva s;
    cin>>n;
    for (i=1;i<=n;++i) {
        cin>>comanda;
        if (comanda == "cd") {
            cin>>argument;
            if (argument == "..") {
                s.pop();
            }
            else
                s.push(comanda,argument);
        }
        else if (comanda == "pwd") {
            cout<<s.topArgument()<<endl;
        }
    }
    return 0;
}
