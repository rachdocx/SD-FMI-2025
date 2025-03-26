#include <iostream>
using namespace std;
const int MAXDIM=100005;

int parent(int i) {
  return (i-1)/2; }

int left(int i) { return (2*i + 1); }

int right(int i) { return (2*i + 2); }


void downKey(int h[], int dim_h, int i) {
  //fiul minim
  while (left(i) < dim_h) {
    int smallest = left(i);
    int r = right(i);

    if (r < dim_h && h[r] < h[smallest])
      smallest = r;
    if (h[i] > h[smallest])
      swap(h[i], h[smallest]);
    else
      break;
    i = smallest;
  }
}

int minim(int h[]){
  return h[0];
}
int extractMin(int h[], int &dim_heap){
  if (dim_heap==0)
    return -1;
  int x=h[0];
  h[0] = h[dim_heap-1];
  dim_heap--;
  downKey(h,dim_heap,0);
  return x;
}

void upKey(int h[], int dim_heap, int i){ // HEAP_UP
  int j=parent(i);
  while (i != 0 && h[j] > h[i])
  {
    swap( h[i],  h[j]);
    i = j;
    j=parent(i);

  }
  //se poate fara swap, doar il cobor si pun pe h[i] cand ii gasesc locul
}
void insert(int h[], int &dim_heap, int x){
  int i = dim_heap;
  h[i] = x;
  dim_heap++;
  upKey(h,dim_heap,i);

}
void print(int h[], int  dim_heap){
  for(int i=0;i<dim_heap;i++)
    cout<<h[i]<<" ";
}
//cele mai mici k elemente folosind heaps
int main(){

  int n=10;
  int k=3;
  int h[MAXDIM];
  int dim_h=0;
  int x;
  for(int i=0;i<k;i++){
    cin>>x;
    insert(h,dim_h,x); //memoram in heap primele k
  }
  for(int i = k; i < n ; i++){
    cin >> x;
    if(x > h[0]){
      extractMin(h,dim_h);
      insert(h,dim_h,x);
    }
  }
  for(int i = 0; i < k; i++)
    cout<<h[i]<<" ";
  return 0;
}