#include <iostream>

using namespace std;
struct Stiva {
    int val;
    Stiva *next;
};

void push(Stiva *&varf, int x) {
    Stiva *nou = new Stiva;
    nou->val = x;
    nou->next = varf;
    varf = nou;
}

void pop(Stiva *&varf) {
    if (varf != NULL) {
        varf = varf->next;
    }
}

int top(Stiva *varf) {
    return varf->val;
}

bool este_vida(Stiva *varf) {
    return varf == NULL;
}
int n, m, k;
int h[2005][2005];

int st[2005][2005];
int dr[2005][2005];
int sus[2005][2005];
int jos[2005][2005];

int minim(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}


int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> h[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        Stiva *s = NULL;
        for (int j = 0; j < m; j++) {
            while (!este_vida(s) && h[i][top(s)] <= h[i][j]) {
                pop(s);
            }
            if (este_vida(s)) {
                st[i][j] = minim(k, j);
            } else {
                st[i][j] = minim(k, j - top(s) - 1);
            }
            push(s, j);
        }
        while(!este_vida(s)) pop(s);
        s = NULL;
        for (int j = m - 1; j >= 0; j--) {
            while (!este_vida(s) && h[i][top(s)] <= h[i][j]) {
                pop(s);
            }
            if (este_vida(s)) {
                dr[i][j] = minim(k, m - 1 - j);
            } else {
                dr[i][j] = minim(k, top(s) - j - 1);
            }
            push(s, j);
        }
        while(!este_vida(s)) pop(s);
    }

    for (int j = 0; j < m; j++) {
        Stiva *s = NULL;
        for (int i = 0; i < n; i++) {
            while (!este_vida(s) && h[top(s)][j] <= h[i][j]) {
                pop(s);
            }
            if (este_vida(s)) {
                sus[i][j] = minim(k, i);
            } else {
                sus[i][j] = minim(k, i - top(s) - 1);
            }
            push(s, i);
        }
        while(!este_vida(s)) pop(s);
        s = NULL;
        for (int i = n - 1; i >= 0; i--) {
            while (!este_vida(s) && h[top(s)][j] <= h[i][j]) {
                pop(s);
            }
            if (este_vida(s)) {
                jos[i][j] = minim(k, n - 1 - i);
            } else {
                jos[i][j] = minim(k, top(s) - i - 1);
            }
            push(s, i);
        }
        while(!este_vida(s)) pop(s);
    }
    int maxim = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int total = 1 + st[i][j] + dr[i][j] + sus[i][j] + jos[i][j];
            if (total > maxim) {
                maxim = total;
            }
        }
    }
    cout << maxim << endl;
    return 0;
}