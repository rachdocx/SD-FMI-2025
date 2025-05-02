#include <iostream>
#include<vector>
#include <fstream>
using namespace std;

ifstream fin("lca.in");
ofstream fout("lca.out");

const int nmax=100005;

int n,m,sz;
int tati[100005];
vector<int>L[nmax];
int e[2*nmax];
int niv[2*nmax];

void Euler(int nod, int lvl){

    e[sz]=nod;
    niv[sz]=lvl;
    sz++;
    for(int fiu : L[nod]){
      Euler(fiu,lvl+1);
      e[sz]=nod;
      niv[sz]=lvl;
      sz++;
    }
}

int main(){
    fin>>n>>m;
    for(int i=0;i<n;i++){
      int j;
      fin>>j;
      L[j-1].push_back(i);
    }
    Euler(0, 0);
    for(int i=0;i<sz;i++){
      cout<<e[i]+1<<" ";
    }


    return 0;
}