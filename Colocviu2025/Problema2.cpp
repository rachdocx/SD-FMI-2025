#include <iostream>
#include <fstream>
using namespace std;
int n,v[2002];
const int NMAX = 100001;
int H[NMAX];
int sz;
int parent(int pos) {
    return pos / 2;
}
int left_son(int pos) {
    return 2 * pos;
}
int right_son(int pos) {
    return 2 * pos + 1;
}
void up(int pos) {
    while (pos > 1 && H[pos] < H[parent(pos)]) {
        swap(H[pos], H[parent(pos)]);
        pos = parent(pos);
    }
}
void down(int pos) {
    while (1) {
        if (left_son(pos) > sz) {
            break;
        }
        int next_pos = left_son(pos);
        if (right_son(pos) <= sz && H[right_son(pos)] < H[next_pos]) {
            next_pos = right_son(pos);
        }
        if (H[pos] < H[next_pos]) {
            break;
        } else {
            swap(H[pos], H[next_pos]);
            pos = next_pos;
        }
    }
}
void sterge_radacina() {
    swap(H[1], H[sz]);
    sz--;
    down(1);
}
void inserare(int x) {
    sz++;
    H[sz] = x;
    up(sz);
}
int minim() {
    return H[1];
}
int main() {
    cin>>n;
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        inserare(x);
    }
    int suma =0;
    while (sz != 1) {
        int min1, min2;
        min1 = minim();
        sterge_radacina();
        min2 = minim();
        sterge_radacina();
        int op = min1+min2;
        suma += op;
        inserare(op);
    }
    cout<<suma;
    return 0;
}
