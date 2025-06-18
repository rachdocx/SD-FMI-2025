#include <iostream>
using namespace std;

struct bt {
    int val;
    bt *left, *right;
};

void inserare(bt * &root, int x) {
    if (root == nullptr) {
        root = new bt;
        root->val = x;
        root->right = nullptr;
        root->left = nullptr;
    } else {
        if (x < root->val)
            inserare(root->left, x);
        else
            inserare(root->right, x);
    }
}

bool cautare(bt * &root, int x) {
    if (root == nullptr) {
        return false;
    } else {
        if (root->val == x)
            return true;
        else {
            if (x < root->val)
                return cautare(root->left, x);
            else
                return cautare(root->right, x);
        }
    }
}

bt *succesor(bt *root) {
    root = root->right;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

void stergere(bt * &root, int x) {
    if (root != nullptr) {
        if (root->val == x) {
            if (root->left == nullptr && root->right == nullptr)
                delete root;
            else {
                if (root->left == nullptr) {
                    bt *aux = root->right;
                    delete root;
                    root = aux;
                } else if (root->right == nullptr) {
                    bt *aux = root->left;
                    delete root;
                    root = aux;
                } else {
                    bt *s = succesor(root);
                    swap(root->val, s->val);
                    stergere(s, s->val);
                }
            }
        } else if (x < root->val) {
            stergere(root->left, x);
        } else {
            stergere(root->right, x);
        }
    }
}
int main()
{
    bt* root=nullptr;
    inserare(root,3);
    inserare(root,2);
    inserare(root,7);
    inserare(root,9);
    inserare(root,1);
    inserare(root,8);
    stergere(root,7);
    cout<<cautare(root,7);
    return 0;
}