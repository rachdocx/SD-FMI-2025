#include <iostream>
using namespace std;
struct node{
  int val;
  node *l, *r;
} *root;
void inorder(node *root){
  if(root != NULL){
    inorder(root->l);
    cout<<root->val<<" ";
    inorder(root->r);
  }
}
//preord RSD
//inord SRD
//postord SDR
int main(){
  cout << "Hello World";
  return 0;
}