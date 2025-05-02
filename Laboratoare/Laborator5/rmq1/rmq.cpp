#include <iostream>
#include <fstream>
#include <cmath>
/**
 *Se da un vector cu N elemente. Scrieti un program care raspunde la M intrebari de tipul "Care este elementul minim din intervalul [x,y]?"
 *
 Pe prima linie a fisierului rmq.in sunt date numerele N si M. Urmatoarele N linii vor contine cate un numar reprezentand elementele
 vectorului. Urmatoarele M linii vor contine cate 2 numere reprezentand valorile x si y care definesc intrebarile.
 **/
using namespace std;
ifstream f("rmq.in");
ofstream g("rmq.out");
long rmq[100000][20];
int main(){
    int n,m,i,j,x,y,k;
    f>>n>>m;
    for(i=0;i<n;i++) {
        f >> rmq[i][0];
    }
    for (j= 1; j<log2(n); j++) {
        for (i=0; i < n - (1<<j); i++) {
            rmq[i][j] = min(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
        }
    }

    for (int nr = 1; nr <= m; ++nr) {
        f >> x >> y;
        --x;
        --y;
        k = int(log2(y-x+1));
        int minrmq = min(rmq[x][k], rmq[y-(1<<k) + 1][k]);
        g << minrmq << endl;
    }
    return 0;
}