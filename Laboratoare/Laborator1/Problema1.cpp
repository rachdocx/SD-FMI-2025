#include <iostream>
using namespace std;

struct nod {
  char val;
  nod* next;
};

void push(nod*& top, char c) {
  nod* nou = new nod;
  nou->val = c;
  nou->next = top;
  top = nou;
}

void pop(nod*& top) {
  if (top == NULL) {
    return;
  }
  nod* temp = top;
  top = top->next;
  delete temp;
}

char peek(nod*& top) {
  if (top == NULL) {
    return 0;
  }
  return top->val;
}

bool empty(nod*& top) {
  return top == NULL;
}

int main() {
  string s;
  nod* s1 = NULL;

  for (char c : s) {
    if (c == '(' || c == '{' || c == '[') {
      push(s1, c);
    } else {
      if (empty(s1)) {

        return 0;
      }
      char d = peek(s1);
      if ((d == '(' && c == ')') || (d == '[' && c == ']') || (d == '{' && c == '}')) {
        pop(s1);
      } else {
       // Dacă există o neconcordanță de tipul {(] sau [)}
        return 0;
      }
    }
  }

  if (empty(s1)) {
    return 1;
  } else {
    return 0";
  }
  return 0;
}
